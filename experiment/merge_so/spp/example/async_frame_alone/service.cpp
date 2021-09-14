#include "sppincl.h"
#include "session_mgr.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include "msg.h"
#include "GetState.h"
#include <string.h>


int Init(CAsyncFrame* pFrame, CMsgBase* pMsg)
{
    return STATE_ID_GET;
}

int Fini(CAsyncFrame* pFrame, CMsgBase* pMsg)
{
    CMsg *msg = (CMsg *) pMsg;

    printf(  "recv data len: %d", msg->recv_byte_count);
    std::string info;
    pMsg->GetDetailInfo(info);
    printf( "%s\n", info.c_str());

    return 0;
}

int main(int argc, char* argv[])
{
    int iRet = 0;
    //Init AsyncFrame
    printf("init begin\n");
    iRet = CAsyncFrame::Instance()->InitFrameWithoutWorker();
    if(iRet != 0)
    {
        printf("init failed, iRet %d\n", iRet);
        return -1;
    } else
    {
        printf("init success\n");
    }

    CAsyncFrame::Instance()->RegCallback(CAsyncFrame::CBType_Init, Init);
    CAsyncFrame::Instance()->RegCallback(CAsyncFrame::CBType_Fini, Fini);
    CGetState* pState = new CGetState();
    CAsyncFrame::Instance()->AddState(STATE_ID_GET, pState);

    //Process Msg
    CMsg *msg = new CMsg;
    msg->SetInfoFlag(true);
    msg->SetMsgTimeout(0);
    char input_buff[] = "hello world";
    int input_len = sizeof(input_buff);
    memcpy(msg->input_buff, input_buff, input_len);
    msg->input_byte_len = input_len;
    CAsyncFrame::Instance()->Process( msg );

    //Run State Machine
    while(true) {
        ASYNC_SPP_II::CSessionMgr::Instance()->run(true);
        if(pState->bFinished) break;
    }
    printf("process msg done");
    
    //Destroy Frame
    CAsyncFrame::Instance()->FiniFrame();
    CAsyncFrame::Destroy();
    return 0;
}

