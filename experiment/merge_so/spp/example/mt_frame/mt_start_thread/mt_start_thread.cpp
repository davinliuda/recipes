/**
 *  @filename Relay_task.cpp
 *  @info     微线程TASK模型demo
 */
#include "syncincl.h"   /* spp微线程需要包含的头文件,里面会依赖sppincl.h */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define REMOTE_IP "127.0.0.1"
#define REMOTE_PORT 5574
#define MAX_BUFF_SIZE 1024

char *format_time( time_t tm);

typedef struct SendPkg
{
    int size;
    char buf[MAX_BUFF_SIZE];
} SendPkg;

void* handle_msg(void * send_pkg)
{
    struct sockaddr_in server_addr;
    /* 获取目的地址信息, 简单示例 */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(REMOTE_IP);
    server_addr.sin_port = htons(REMOTE_PORT);

    SendPkg* pkg = (SendPkg*)send_pkg;
    /* 使用UDP一发一收微线程接口 */
    int max_len = MAX_BUFF_SIZE;
    int ret = mt_udpsendrcv(&server_addr, (void*)pkg->buf, pkg->size, pkg->buf, max_len, 100); 
    if (ret < 0)
    {
        fprintf(stderr, "new thread handle_msg udpsendrcv failed: ret %d\n", ret);
        free(send_pkg);
    }
    else
    {
        printf("new thread handle_msg rcvd: %s\n", pkg->buf);
        free(send_pkg);
    }
    return NULL;
}

/** 
 * @brief TASK模型示例 - MSG
 */
class ExampleMsg : public CSyncMsg 
{
public:

    /**
     * @brief 同步消息处理函数
     * @return 0, 成功-用户自己回包到前端,框架不负责回包处理
     *         其它, 失败-框架关闭与proxy连接, 但不负责回业务报文
     */
    virtual int HandleProcess(); 
};

/** 
 * @brief TASK模型示例 - MSG process
 * @return 0, 成功-用户自己回包到前端,框架不负责回包处理
 *         其它, 失败-框架关闭与proxy连接, 但不负责回业务报文
 */
int ExampleMsg::HandleProcess()
{

    SendPkg* pkg = (SendPkg*)malloc(sizeof(SendPkg));
    memcpy(pkg->buf, (char*)_msg_buff.data(), (int)_msg_buff.size());
    pkg->size = (int)_msg_buff.size();

    
    // create a new thread to recv
    mt_start_thread((void*)handle_msg, (void*)pkg);
    
    blob_type blob;
    blob.data = (char*)_msg_buff.data();
    blob.len  = _msg_buff.size();
    
    this->SendToClient(blob);
    return 0;
}

/**
 * @brief 业务模块初始化插件接口（可选实现proxy,worker）
 * @param arg1 - 配置文件
 * @param arg2 - 服务器容器对象
 * @return 0 - 成功, 其它失败
 */
extern "C" int spp_handle_init(void* arg1, void* arg2)
{
    const char * etc  = (const char*)arg1;
    CServerBase* base = (CServerBase*)arg2;

    base->log_.LOG_P_PID(LOG_DEBUG, "spp_handle_init, config:%s, servertype:%d\n", etc, base->servertype());

    if (base->servertype() == SERVER_TYPE_WORKER)
    {
        /* 初始化框架 */
        int iRet = CSyncFrame::Instance()->InitFrame(base);
        if (iRet < 0)
        {
            base->log_.LOG_P_PID(LOG_FATAL, "Sync framework init failed, ret:%d\n", iRet);
            return -1;
        }
    }
    else
    {
        /* proxy init */
    }
    
    return 0;
}


/**
 * @brief 业务模块检查报文合法性与分包接口(proxy)
 * @param flow - 请求包标志
 * @param arg1 - 数据块对象
 * @param arg2 - 服务器容器对象
 * @return ==0  数据包还未完整接收,继续等待
 *         > 0  数据包已经接收完整, 返回包长度
 *         < 0  数据包非法, 连接异常, 将断开TCP连接
 */
extern "C" int spp_handle_input(unsigned flow, void* arg1, void* arg2)
{
    blob_type* blob = (blob_type*)arg1;
    TConnExtInfo* extinfo = (TConnExtInfo*)blob->extdata;
    CServerBase* base = (CServerBase*)arg2;

    base->log_.LOG_P(LOG_DEBUG, "spp_handle_input, %d, %d, %s, %s\n",
                     flow,
                     blob->len,
                     inet_ntoa(*(struct in_addr*)&extinfo->remoteip_),
                     format_time(extinfo->recvtime_));

    return blob->len;
}

/**
 * @brief 业务模块报文按worker组分发接口(proxy)
 * @param flow - 请求包标志
 * @param arg1 - 数据块对象
 * @param arg2 - 服务器容器对象
 * @return 处理该报文的worker组id
 */
extern "C" int spp_handle_route(unsigned flow, void* arg1, void* arg2)
{
    return 1;
}

/**
 * @brief 业务模块报文,worker组的处理接口(worker)
 * @param flow - 请求包标志
 * @param arg1 - 数据块对象
 * @param arg2 - 服务器容器对象
 * @return 0 - 成功,其它表示失败
 */
extern "C" int spp_handle_process(unsigned flow, void* arg1, void* arg2)
{
    blob_type   * blob    = (blob_type*)arg1;
    TConnExtInfo* extinfo = (TConnExtInfo*)blob->extdata;

    CServerBase* base  = (CServerBase*)arg2;
    CTCommu    * commu = (CTCommu*)blob->owner;

    base->log_.LOG_P_PID(LOG_DEBUG, "spp_handle_process, %d, %d, %s, %s\n",
                         flow,
                         blob->len,
                         inet_ntoa(*(struct in_addr*)&extinfo->remoteip_),
                         format_time(extinfo->recvtime_));

    ExampleMsg *msg = new ExampleMsg;
    if (!msg) {
        blob_type respblob;
        respblob.data  = NULL;
        respblob.len   = 0;
        commu->sendto(flow, &respblob, NULL);
        base->log_.LOG_P_PID(LOG_ERROR, "close conn, flow:%u\n", flow);

        return -1;
    }

    /* 设置msg信息 */
    msg->SetServerBase(base);
    msg->SetTCommu(commu);
    msg->SetFlow(flow);
    msg->SetMsgTimeout(100);
    msg->SetReqPkg(blob->data, blob->len); /* 微线程有独立空间,这里要拷贝一次报文 */

    CSyncFrame::Instance()->Process(msg);

    return 0;
}


/**
 * @brief 业务服务终止接口函数(proxy/worker)
 * @param arg1 - 保留
 * @param arg2 - 服务器容器对象
 * @return 0 - 成功,其它表示失败
 */
extern "C" void spp_handle_fini(void* arg1, void* arg2)
{
    CServerBase* base = (CServerBase*)arg2;
    base->log_.LOG_P(LOG_DEBUG, "spp_handle_fini\n");

    if ( base->servertype() == SERVER_TYPE_WORKER )
    {
        CSyncFrame::Instance()->Destroy();
    }
}

char *format_time( time_t tm)
{
    static char str_tm[1024];
    struct tm tmm;
    memset(&tmm, 0, sizeof(tmm) );
    localtime_r((time_t *)&tm, &tmm);

    snprintf(str_tm, sizeof(str_tm), "[%04d-%02d-%02d %02d:%02d:%02d]",
             tmm.tm_year + 1900, tmm.tm_mon + 1, tmm.tm_mday,
             tmm.tm_hour, tmm.tm_min, tmm.tm_sec);

    return str_tm;
}
