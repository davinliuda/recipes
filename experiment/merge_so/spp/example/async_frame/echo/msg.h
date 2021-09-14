/*
 * =====================================================================================
 *
 *       Filename:  msg.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/21/2010 03:31:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ericsha (shakaibo), ericsha@tencent.com
 *        Company:  Tencent, China
 *
 * =====================================================================================
 */

#ifndef __MSG_H__
#define __MSG_H__
#include "MsgBase.h"

USING_ASYNCFRAME_NS;

#define STATE_ID_FINISHED   0
#define STATE_ID_GET        1
#define STATE_ID_GET2       2

class CMsg
    : public CMsgBase
{
    public:
        CMsg(): input_byte_len(0), recv_byte_count(0) {};
        char input_buff[1024]; //用户输入
        int input_byte_len;
        char recv_buff[4096]; //从服务器接收的数据
        int recv_byte_count;
};


#endif
