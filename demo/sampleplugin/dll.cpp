#include"plugin.h"
#include <dlfcn.h>
#include<iostream>
using namespace std;
Plugin* gInstance;
Create_t* gCreate;
Destory_t* gDestory;

int main()
{
	
	char* pErr;
	void* dll_handler = dlopen("libsampleplugin.so",RTLD_NOW|RTLD_GLOBAL);
	if(!dll_handler){
		cout<<dlerror()<<endl;
		return 0;
	}
	gCreate = (Create_t*)dlsym(dll_handler,"Create");	
	pErr = dlerror();
	if(pErr){
		cout<<"dlsym error:"<<pErr<<endl;
		return 0;
	}
	gDestory = (Destory_t*)dlsym(dll_handler, "Destory");
        pErr = dlerror();
        if(pErr){
                cout<<"dlsym error:"<<pErr<<endl;
                return 0;
        }

	gInstance = gCreate();
	gInstance->Print();
	gDestory(gInstance);
	dlclose(dll_handler);
}
