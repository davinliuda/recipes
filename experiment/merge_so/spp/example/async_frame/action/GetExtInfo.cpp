/*
 * =====================================================================================
 *
 *       Filename:  GetExtInfo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/21/2010 03:04:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ericsha (shakaibo), ericsha@tencent.com
 *        Company:  Tencent, China
 *
 * =====================================================================================
 */

#include "GetExtInfo.h"
#include "msg.h"
#include "sppincl.h"
#include <string.h>

extern int seq;

// 请求打包
int CGetExtInfo::HandleEncode( CAsyncFrame *pFrame,
        char *buf,
        int &len,
        CMsgBase *pMsg)
{
    CMsg *msg = (CMsg*)pMsg;

    memcpy(buf, msg->input_buff, msg->input_byte_len);
    len = msg->input_byte_len;

    pFrame->FRAME_LOG( LOG_DEBUG, "CGetExtInfo::HandleEncode. send len\n", msg->input_byte_len);
    return 0;
}

// 回应包完整性检查
int CGetExtInfo::HandleInput( CAsyncFrame *pFrame,
        const char *buf,
        int len,
        CMsgBase *pMsg)
{
    pFrame->FRAME_LOG( LOG_DEBUG, "CGetExtInfo::HandleInput. buf len: %d\n", len);
    CMsg *msg = (CMsg*)pMsg;
    if(len == msg->input_byte_len)
        return len;

    return 0;
}

// 回应包处理
int CGetExtInfo::HandleProcess( CAsyncFrame *pFrame,
        const char *buf,
        int len,
        CMsgBase *pMsg)
{
    CMsg *msg = (CMsg*)pMsg;
    char prefix[] = "\nGetExtInfo Recv: ";
    memcpy(&(msg->recv_buff[msg->recv_byte_count]), prefix, strlen(prefix));
    msg->recv_byte_count += strlen(prefix);
    memcpy(&(msg->recv_buff[msg->recv_byte_count]), buf, len);
    msg->recv_byte_count += len;

    pFrame->FRAME_LOG( LOG_DEBUG, "CGetExtInfo::HandleProcess.  recvd len: %d;\n", 
            len);

    return 0;
}


int CGetExtInfo::HandleError( CAsyncFrame *pFrame,
        int err_no,
        CMsgBase *pMsg)
{
    pFrame->FRAME_LOG( LOG_ERROR, "CGetExtInfo::HandleError. errno: %d\n", err_no);

    return 0;
}
