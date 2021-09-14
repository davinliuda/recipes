#include <iostream>
#include "syncincl.h"
#include "sppincl.h"
#include "a.h"
int a = 3;


class MyMessage : public CSyncMsg {
public:
	virtual int HandleProcess()
	{
		GetServerBase()->log_.LOG_P_ALL(0, "myMessage process.req:%s, len:%d, a:%d\n", GetReqPkg().c_str(), GetReqPkg().size(), AA::Instace()->a++);
		blob_type resblob;
		resblob.data = (char*)GetReqPkg().c_str();
		resblob.len = GetReqPkg().size();
		int ret = SendToClient(resblob);
		GetServerBase()->log_.LOG_P_ALL(0, "SendToClient ret:%d\n", ret);
		return 0;		
	}
};

extern "C" int spp_handle_init(void* arg1, void* arg2)
{
	CServerBase* base = (CServerBase*)arg2;

	if (base->servertype() == SERVER_TYPE_WORKER) {
		int ret = CSyncFrame::Instance()->InitFrame(base);
		if (ret != 0) {
		    base->log_.LOG_P_ALL(0, "spp_handle_init failed:%d\n", a);
		}
	}
	base->log_.LOG_P_ALL(0, "spp_handle_init hahahaha:%d\n", a);
	return 0;
}

extern "C" int spp_handle_input(unsigned flow, void* arg1, void* arg2)
{
	CServerBase* base = (CServerBase*)arg2;
	blob_type* blob = (blob_type*)arg1;
	base->log_.LOG_P_ALL(0, "spp_handle_input hahahaha:a:%d, data%d, data_len:%d\n", a, blob->data, blob->len);
	return blob->len;
}

extern "C" int spp_handle_route(unsigned flow, void* arg1, void* arg2)
{
	return 1;
}


extern "C" int spp_handle_process(unsigned flow, void* arg1, void* arg2)
{
	CServerBase* base = (CServerBase*)arg2;
        blob_type* blob = (blob_type*)arg1;
	base->log_.LOG_P_ALL(0, "spp_handle_process hahahaha:a:%d, data%d, data_len:%d\n", a, blob->data, blob->len);
	
	CTCommu* commu = (CTCommu*)blob->owner;
	TConnExtInfo* extinfo = (TConnExtInfo*)blob->extdata;	

	MyMessage* message = new MyMessage();
	message->SetServerBase(base);
    	message->SetTCommu(commu);
    	message->SetFlow(flow);	
	message->SetReqPkg(blob->data,  blob->len);

	CSyncFrame::Instance()->Process(message);
	return 0;
}

extern "C" void spp_handle_fini(void* arg1, void* arg2)
{
}

extern "C" void spp_handle_loop(void* arg1)
{
}
