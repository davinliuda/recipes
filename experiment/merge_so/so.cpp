#include <dlfcn.h>
#include <iostream>
#include "syncincl.h"
#include "sppincl.h"

int a = 0;


void* handle1 = NULL;
void* handle2 = NULL;

typedef int (*FUNC_INIT)(void* arg1, void* arg2);
typedef int (*FUNC_INPUT)(unsigned flow, void* arg1, void* arg2);
typedef int (*FUNC_ROUTE)(unsigned flow, void* arg1, void* arg2);
typedef int (*FUNC_PROCESS)(unsigned flow, void* arg1, void* arg2);
typedef int (*FUNC_FINI)(void* arg1, void* arg2);


FUNC_INIT f1 = NULL;
FUNC_INPUT f2 = NULL;
FUNC_ROUTE f3 = NULL;
FUNC_PROCESS f4 = NULL;
FUNC_FINI f5 = NULL;

FUNC_INIT f11 = NULL;
FUNC_INPUT f12 = NULL;
FUNC_ROUTE f13 = NULL;
FUNC_PROCESS f14 = NULL;
FUNC_FINI f15 = NULL;


extern "C" int spp_handle_init(void* arg1, void* arg2)
{
	CServerBase* base = (CServerBase*)arg2;
	base->log_.LOG_P_ALL(0, "hahahaha:%d\n", a);

	handle1 = dlopen("./libso1.so", RTLD_NOW|RTLD_GLOBAL);
	if (!handle1) {
		return -1;
	}

	f1 = (FUNC_INIT)dlsym(handle1, "spp_handle_init");
	f2 = (FUNC_INPUT)dlsym(handle1, "spp_handle_input");
	f3 = (FUNC_ROUTE)dlsym(handle1, "spp_handle_route");
	f4 = (FUNC_PROCESS)dlsym(handle1, "spp_handle_process");
	f5 = (FUNC_FINI)dlsym(handle1, "spp_handle_fini");;
				
	if(f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL || f5 == NULL ) {
 		return -1;
	}
			
	handle2 = dlopen("./libso2.so", RTLD_NOW|RTLD_GLOBAL);
	if (!handle2) {
		return -1;
	}

	f11 = (FUNC_INIT)dlsym(handle2, "spp_handle_init");
        f12 = (FUNC_INPUT)dlsym(handle2, "spp_handle_input");
        f13 = (FUNC_ROUTE)dlsym(handle2, "spp_handle_route");
        f14 = (FUNC_PROCESS)dlsym(handle2, "spp_handle_process");
        f15 = (FUNC_FINI)dlsym(handle2, "spp_handle_fini");;	
	
	if(f11 == NULL || f12 == NULL || f13 == NULL || f14 == NULL || f15 == NULL ) {
                return -1;
        }
	/*if (base->servertype() == SERVER_TYPE_WORKER) {
                int ret = CSyncFrame::Instance()->InitFrame(base);
                if (ret != 0) {
                    base->log_.LOG_P_ALL(0, "spp_handle_init failed:%d\n", a);
                }
        }*/

	char* arg111 = "/usr/local/services/spp_test_private_davinliu-2.3/client/test_private_davinliu/conf/ad_leads_data_svr.conf";
	char* arg222 = "/usr/local/services/spp_test_private_davinliu-2.3/client/test_private_davinliu/conf/im_monitor_report_svr.conf"; 
	int ret1 = f1((void*)arg111, arg2);
	if (ret1 != 0) {
		base->log_.LOG_P_ALL(0, "spp_handle_init failed:%d\n", ret1);
		return ret1;
	}
	int ret2= f11((void*)arg222, arg2);
	if (ret2 != 0) {
                base->log_.LOG_P_ALL(0, "spp_handle_init failed:%d\n", ret2);
                return ret2;
        }
	return 0;
}

extern "C" int spp_handle_input(unsigned flow, void* arg1, void* arg2)
{
	blob_type* blob = (blob_type*)arg1;
	
	CServerBase* base = (CServerBase*)arg2;
        base->log_.LOG_P_ALL(1, "spp_handle_input hahahaha:a:%d, data:%s, data_len:%d\n", a, blob->data, blob->len);
	return f2(flow, arg1, arg2);	
}

extern "C" int spp_handle_route(unsigned flow, void* arg1, void* arg2)
{
	return 1;
}


extern "C" int spp_handle_process(unsigned flow, void* arg1, void* arg2)
{
	blob_type* blob = (blob_type*)arg1;
	CServerBase* base = (CServerBase*)arg2;
	base->log_.LOG_P_ALL(1, "spp_handle_process hahahaha:a:%d, data:%s, data_len:%d\n", a, blob->data, blob->len);
	if(flow % 2 == 0 ) {
		return f4(flow, arg1, arg2);
	} else {
		return f14(flow, arg1, arg2);
	}
}

extern "C" void spp_handle_fini(void* arg1, void* arg2)
{
}

extern "C" void spp_handle_loop(void* arg1)
{
}
