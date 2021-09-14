/*
 * =====================================================================================
 *
 *       Filename:  GetState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/21/2010 03:39:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ericsha (shakaibo), ericsha@tencent.com
 *        Company:  Tencent, China
 *
 * =====================================================================================
 */

#include "GetState.h"
#include "GetInfo.h"
#include "ActionInfo.h"
#include "AsyncFrame.h"
#include "CommDef.h"
#include "msg.h"


int CGetState::HandleEncode(CAsyncFrame *pFrame,
        CActionSet *pActionSet,
        CMsgBase *pMsg) 
{
    static CGetInfo GetInfo;

    CActionInfo *pAction1 = new CActionInfo(512);
    pAction1->SetID(1);
    pAction1->SetDestIp("127.0.0.1");
    pAction1->SetDestPort(5575);
    pAction1->SetProto(ProtoType_UDP);
    pAction1->SetActionType(ActionType_SendRecv);
    pAction1->SetTimeout(200);
    pAction1->SetIActionPtr((IAction *)&GetInfo);

    pActionSet->AddAction(pAction1);



    return 0;
}

int CGetState::HandleProcess(CAsyncFrame *pFrame,
        CActionSet *pActionSet,
        CMsgBase *pMsg)
{
    return STATE_ID_FINISHED;
}
