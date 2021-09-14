/*
 * =====================================================================================
 *
 *       Filename:  AsyncFrame.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2010 03:27:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ericsha (shakaibo), ericsha@tencent.com
 *        Company:  Tencent, China
 *
 * =====================================================================================
 */

#ifndef __ASYNC_FRAME_H__
#define __ASYNC_FRAME_H__
#include <map>
#ifdef ASYNC_FRAME_ALONE
#include <stdio.h>
#else
#include <serverbase.h>
#endif
#include "timerlist.h"
#include "poller.h"

class CPollerUnit;
class CTimerUnit;

#include "PtrMgr.h"

BEGIN_ASYNCFRAME_NS

class IState;
class CActionSet;
class CActionInfo;
class CMsgBase;
using namespace spp::comm;


#ifdef ASYNC_FRAME_ALONE
#define FRAME_LOG PrintLog
#else
#define FRAME_LOG GetServerBase()->log_.LOG_P_ALL
#endif

class CAsyncFrame
{
    public:
        enum CBType {
            CBType_Init = 0,        // è¯·æ±‚å¼€å§‹å¤„ç†æ—¶å›è°ƒ
            CBType_Fini,            // è¯·æ±‚å¤„ç†å®Œæˆæ—¶å›è°ƒ
            CBType_Overload,        // å¼‚æ­¥æ¡†æ¶è¿‡è½½æ—¶å›è°ƒ
            CBType_Num = 10,
        };

        typedef int (*CBFunc)(CAsyncFrame*, CMsgBase*);     // å›è°ƒå‡½æ•°åŸå‹
        typedef std::map<int, IState*>  StateMap;           // çŠ¶æ€Map

        friend class CActionSet;
        friend class CActionInfo;

    public:
        static CAsyncFrame* Instance (void);
        static void Destroy (void);

        CAsyncFrame();
        ~CAsyncFrame();

#ifdef ASYNC_FRAME_ALONE
        /**
         * åˆå§‹åŒ–å¼‚æ­¥æ¡†æ¶ï¼Œå•ç‹¬ä½¿ç”¨sppå¼‚æ­¥æ¡†æ¶æ—¶ä½¿ç”¨
         *
         * @param nPendingConnNum Pendingç±»å‹è¿æ¥æ•°ä¸Šé™
         *
         * @return 0: æˆåŠŸï¼› å…¶ä»–ï¼šå¤±è´¥
         *
         */
        int InitFrameWithoutWorker(int nPendingConnNum = 100);
        static void PrintLog(int log_level, const char *fmt, ... ) {
            return;
        }
#else
        /**
         * ³õÊ¼»¯Òì²½¿ò¼Ü£¬ÓÉ²å¼şÔÚworker½ø³ÌµÄspp_handle_initÀïµ÷ÓÃ
         *
         * @param pServBase CServerBase¶ÔÏóÖ¸Õë
         * @param pPollerUnit CPollerUnit¶ÔÏóÖ¸Õë£¬´Ó¾É°æ±¾µÄÒì²½½Ó¿Ú»ñÈ¡
         * @param pTimerUnit CTimerUnit¶ÔÏóÖ¸Õë£¬´Ó¾É°æ±¾µÄÒì²½½Ó¿Ú»ñÈ¡
         * @param nPendingConnNum PendingÀàĞÍÁ¬½ÓÊıÉÏÏŞ
         *
         * @return 0: ³É¹¦£» ÆäËû£ºÊ§°Ü
         *
         */
        int InitFrame(CServerBase *pServBase, 
                        CPollerUnit *pPollerUnit,
                        CTimerUnit *pTimerUnit,
                        int nPendingConnNum = 100);

        /**
         * ³õÊ¼»¯Òì²½¿ò¼Ü£¬ÓÉ²å¼şÔÚworker½ø³ÌµÄspp_handle_initÀïµ÷ÓÃ
         * ±¾½Ó¿ÚÔÚspp2.2.0°æ±¾ÖĞÒıÈë£¬Ôö¼ÓÒì²½¿ò¼Ü¹ıÔØ±£»¤¹¦ÄÜ
         *
         * @param pServBase CServerBase¶ÔÏóÖ¸Õë
         * @param nPendingConnNum PendingÀàĞÍÁ¬½ÓÊıÉÏÏŞ
         * @param nOverloadLimit Òì²½¿ò¼Ü¹ıÔØÉÏÏŞ(ÏŞÖÆÒì²½¿ò¼Üµ±Ç°´¦ÀíµÄÇëÇóÊı)
         *                      ¹ıÔØÊ±»á»Øµ÷CBType_OverloadÀàĞÍº¯Êı, 0:ÎŞ¹ıÔØÏŞÖÆ
         * @param nL5Timeout ÓëL5Agent½»»¥³¬Ê±ÉèÖÃ
         * @param nL5Port l5agent bind port£¬ Ö»ÓĞ·Ç±ê×¼L5²¿Êğ»·¾³ÏÂ²ÅĞèÒªÉèÖÃ
         *
         * @return 0: ³É¹¦£» ÆäËû£ºÊ§°Ü
         *
         */
        int InitFrame2(CServerBase *pServBase, 
                            int nPendingConnNum = 100,
                            int nOverloadLimit = 0,
                            int nL5Timeout = 100,
                            unsigned short nL5Port = 8888);

        /**
        *  »ñÈ¡CServerBase¶ÔÏóÖ¸Õë£¬¸Ã¶ÔÏóÌá¹©ÈÕÖ¾¡¢Í³¼Æ¹¦ÄÜ
        *  ºê¶¨ÒåFRAME_LOGÊÇÎªÁË¼ò»¯ÈÕÖ¾¼ÇÂ¼µÄ¡£
        * 
        *  @return CServerBase¶ÔÏóÖ¸Õë
        **/
        inline CServerBase *GetServerBase()
        {
            return _pServBase;
        }
#endif

        /**
         * ååˆå§‹åŒ–å¼‚æ­¥æ¡†æ¶ï¼Œç”±æ’ä»¶åœ¨workerè¿›ç¨‹çš„spp_handle_finié‡Œè°ƒç”¨
         *
         */
        void FiniFrame();

        /**
         * æ³¨å†Œå›è°ƒå‡½æ•°ï¼Œä¸¤ç§å›è°ƒå‡½æ•°ç±»å‹ï¼š
         * 1) CBType_Init // è¯·æ±‚å¼€å§‹å¤„ç†æ—¶å›è°ƒ, è¯¥å›è°ƒå‡½æ•°è¿”å›å€¼ä¸ºå¤„ç†è¯·æ±‚çš„ç¬¬ä¸€ä¸ªçŠ¶æ€IDï¼Œé»˜è®¤çŠ¶æ€IDä¸º1
         * 2) CBType_Fini // è¯·æ±‚å¤„ç†å®Œæˆæ—¶å›è°ƒ, å½“è¯·æ±‚å¤„ç†å®Œæ¯•ï¼ˆå¯èƒ½å‘ç”Ÿé”™è¯¯ï¼‰æ—¶å›è°ƒï¼Œä¸šåŠ¡å¯ä»¥åœ¨è¿™ä¸ªå›è°ƒå‡½æ•°é‡Œè¿›è¡Œå›åŒ…
         * 3) CBType_Overload // æ¡†æ¶è¿‡è½½æ—¶å›è°ƒ, å¿…é¡»ä½¿ç”¨InitFrame2æ–¹æ³•åˆå§‹åŒ–æ¡†æ¶ï¼Œ
         *                       å¹¶ä¸”OverloadLimit > 0ï¼Œè¯·æ±‚æ•°è¶…è¿‡OverloadLimitæ—¶è¢«è°ƒç”¨
         *
         * @param type å›è°ƒå‡½æ•°ç±»å‹
         * @param func å›è°ƒå‡½æ•°
         *
         * @return 0: æˆåŠŸï¼›å…¶ä»–ï¼šå¤±è´¥
         */
        int RegCallback(CBType type, CBFunc func);

        /**
         * æ·»åŠ å¤„ç†è¯·æ±‚æ—¶ä½¿ç”¨çš„æ‰€æœ‰IStateæ´¾ç”Ÿç±»å¯¹è±¡æŒ‡é’ˆï¼Œé€šå¸¸ç”±æ’ä»¶åœ¨spp_handle_initæ–¹æ³•é‡Œè°ƒç”¨
         *
         * @param id çŠ¶æ€ID, å¿…é¡»>0
         * @param pState IStateæ´¾ç”Ÿç±»å¯¹è±¡æŒ‡é’ˆ
         *
         * @return 0: æˆåŠŸï¼›å…¶ä»–ï¼šå¤±è´¥
         */
        int AddState( int id, IState *pState); 

        /**
         * å¤„ç†è¯·æ±‚ï¼Œç”±æ’ä»¶åœ¨spp_handle_processæ–¹æ³•é‡Œè°ƒç”¨
         *
         * @param pMsg CMsgBaseæ´¾ç”Ÿç±»å¯¹è±¡æŒ‡é’ˆï¼Œå­˜æ”¾å’Œè¯·æ±‚ç›¸å…³çš„æ•°æ®ï¼Œè¯¥å¯¹è±¡éœ€è¦æ’ä»¶ä»¥newçš„æ–¹å¼åˆ†é…ï¼Œé‡Šæ”¾ç”±æ¡†æ¶è´Ÿè´£
         *
         * @return 0: æˆåŠŸï¼› å…¶ä»–ï¼šå¤±è´¥
         *
         */ 
        int Process(CMsgBase *pMsg);

        /**
         *  @brief Get msg count processing
         *  @return msg count process
         */
        int GetMsgCount();


    protected:
        // å¯åŠ¨çŠ¶æ€å¤„ç†
        int HandleEncode(int id, CMsgBase *pMsgBase);

        // çŠ¶æ€å®Œæˆï¼ˆæ‰€æœ‰åŠ¨ä½œéƒ½å¤„ç†å®Œæ¯•ï¼‰åçš„å¤„ç†
        int HandleProcess(IState *pState, CActionSet *pActionSet, CMsgBase *pMsg);

        // æ¸…ç©ºçŠ¶æ€è¡¨
        void ClearStateMap();

    protected:
        static CAsyncFrame *_s_instance;
        CPtrMgr<CActionSet, PtrType_New> *_asptr_mgr;
        CPtrMgr<CMsgBase, PtrType_New> *_msgptr_mgr;
        #ifndef ASYNC_FRAME_ALONE
        CServerBase *_pServBase;
        #endif

        CBFunc _cbFunc[CBType_Num];
        
        StateMap _mapState; 

        int _nOverloadLimit;    // æ¡†æ¶è¿‡è½½ä¸Šé™ï¼Œ0ï¼šæ— è¿‡è½½ä¿æŠ¤
        int _nRequestCount;     // æ¡†æ¶æ­£åœ¨å¤„ç†çš„è¯·æ±‚è®¡æ•°

        CActionSet *_pNeedDeleteAS;

};

END_ASYNCFRAME_NS

#endif
