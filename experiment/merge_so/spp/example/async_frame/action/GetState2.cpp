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

#include "GetState2.h"
#include "GetExtInfo.h"
#include "ActionInfo.h"
#include "AsyncFrame.h"
#include "CommDef.h"
#include "msg.h"


int CGetState2::HandleEncode(CAsyncFrame *pFrame,
        CActionSet *pActionSet,
        CMsgBase *pMsg) 
{
    static CGetExtInfo GetExtInfo;

    CActionInfo *pAction3 = new CActionInfo(512);
    pAction3->SetID(3);
    pAction3->SetDestIp("127.0.0.1");
    pAction3->SetDestPort(5574);
    pAction3->SetProto(ProtoType_UDP);
    pAction3->SetTimeout(200);
    pAction3->SetIActionPtr((IAction *)&GetExtInfo);

    pActionSet->AddAction(pAction3);

    return 0;
}

int CGetState2::HandleProcess(CAsyncFrame *pFrame,
        CActionSet *pActionSet,
        CMsgBase *pMsg)
{
    return STATE_ID_FINISHED;
}
