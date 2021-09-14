/**
 * @file mt_alone.cpp
 * @info 微线程单独使用事例
 */

#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "mt_incl.h"

#define  REMOTE_IP      "127.0.0.1"
#define  REMOTE_PORT    5574
#define  SEND_PKG    "hello world"
#define  SEND_PKG_LEN   (sizeof(SEND_PKG) - 1)

// Task事例类:使用UDP单发单收接口
class UdpSndRcvTask
    : public IMtTask
{
public:
    virtual int Process() {
        // 获取目的地址信息, 简单示例
        static struct sockaddr_in server_addr;
        static int initflg = 0;

        if (!initflg) {
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = inet_addr(REMOTE_IP);
            server_addr.sin_port = htons(REMOTE_PORT);
            initflg = 1;
        }

        char buff[1024] = SEND_PKG;
        int  max_len = sizeof(buff);
        
        int ret = mt_udpsendrcv(&server_addr, (void*)buff, SEND_PKG_LEN, buff, max_len, 100);
        if (ret < 0)
        {
            printf("UdpSndRecvTask mt_udpsendrcv failed, ret %d\n", ret);
            return -1;
        }
        else
        {
            printf("UdpSndRcvTask recvd: %s\n", buff);
            return 0;
        }
    };
};


// 检查报文是否接受完成
int CheckPkgLen(void *buf, int len) {
    if (len < (int)SEND_PKG_LEN)
    {
        return 0;
    }

    return SEND_PKG_LEN;
}

// Task事例类，使用TCP连接池单发单收接口
class TcpSndRcvTask
    : public IMtTask
{
public:
    virtual int Process() {
        // 获取目的地址信息, 简单示例
        static struct sockaddr_in server_addr;
        static int initflg = 0;

        if (!initflg) {
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = inet_addr(REMOTE_IP);
            server_addr.sin_port = htons(REMOTE_PORT);
            initflg = 1;
        }

        char buff[1024] = SEND_PKG;
        int  max_len = sizeof(buff);
        
        int ret = mt_tcpsendrcv(&server_addr, (void*)buff, SEND_PKG_LEN, buff, max_len, 100, CheckPkgLen);
        if (ret < 0)
        {
            printf("mt_udpsendrcv failed, ret %d\n", ret);
            return -1;
        }
        else
        {
            printf("TcpSndRcvTask recvd: %s\n", buff);
            return 0;
        }
    };
};

// Task事例类: 业务可以用来验证微线程API可用性
class ApiVerifyTask
    : public IMtTask
{
public:
    virtual int Process() {
        // 调用业务使用微线程API
        printf("This is the api verify task!!!\n");

        return 0;
    };
};

int main(void)
{
    // 初始化微线程框架
    bool init_ok = mt_init_frame();
    if (!init_ok)
    {
        fprintf(stderr, "init micro thread frame failed.\n");
        return -1;
    }

    // 触发微线程切换
    mt_sleep(0);

    UdpSndRcvTask task1;
    TcpSndRcvTask task2;
    ApiVerifyTask task3;

    // 现在原生线程已经在demon的调度中了
    while (true)
    { 
        // 这里示例一个并发操作
        IMtTaskList task_list;
        task_list.push_back(&task1);
        task_list.push_back(&task2);
        task_list.push_back(&task3);

        int ret = mt_exec_all_task(task_list);
        if (ret < 0)
        {
            fprintf(stderr, "execult tasks failed, ret:%d", ret);
            return -2;
        }

        // 循环检查每一个task是否执行成功，即Process的返回值
        for (unsigned int i = 0; i < task_list.size(); i++)
        {
            IMtTask *task = task_list[i];
            int result = task->GetResult();

            if (result < 0)
            {
                fprintf(stderr, "task(%u) failed, result:%d", i, result);
            }
        }
        printf("\n");
        // 睡眠2000ms
        mt_sleep(2000);
    }

    return 0;
}


