/*
 * =====================================================================================
 *
 *       Filename:  GetInfo.cpp
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

#include "GetInfo.h"
#include "msg.h"
#include "sppincl.h"


// 请求打包
int CGetInfo::HandleEncode( CAsyncFrame *pFrame,
        char *buf,
        int &len,
        CMsgBase *pMsg)
{
    CMsg *msg = (CMsg*)pMsg;
    memcpy(buf, msg->input_buff, msg->input_byte_len);
    len = msg->input_byte_len;

    pFrame->FRAME_LOG( LOG_DEBUG, "CGetInfo::HandleEncode. send len: %d\n", len);
    return 0;
}

// 回应包完整性检查
int CGetInfo::HandleInput( CAsyncFrame *pFrame,
        const char *buf,
        int len,
        CMsgBase *pMsg)
{
    CMsg *msg = (CMsg*)pMsg;
    pFrame->FRAME_LOG( LOG_DEBUG, "CGetInfo::HandleInput. buf len: %d;\n", 
            len);
    if(len == msg->input_byte_len)
        return len;

    return 0;
}

// 回应包处理
int CGetInfo::HandleProcess( CAsyncFrame *pFrame,
        const char *buf,
        int len,
        CMsgBase *pMsg)
{
    CMsg *msg = (CMsg*)pMsg;
    char prefix[] = "\nGetInfo Recv: ";
    memcpy(&(msg->recv_buff[msg->recv_byte_count]), prefix, strlen(prefix));
    msg->recv_byte_count += strlen(prefix);
    memcpy(&(msg->recv_buff[msg->recv_byte_count]), buf, len);
    msg->recv_byte_count += len;

    pFrame->FRAME_LOG( LOG_DEBUG, "CGetInfo::HandleProcess. buf len: %d;\n", 
            len);

    return 0;
}


int CGetInfo::HandleError( CAsyncFrame *pFrame,
        int err_no,
        CMsgBase *pMsg)
{
    pFrame->FRAME_LOG( LOG_ERROR, "CGetInfo::HandleError. errno: %d\n", err_no);

    return 0;
}
