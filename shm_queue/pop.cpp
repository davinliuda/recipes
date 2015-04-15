#include"common_codequeue.h"
#include"common_memory.h"
#include<iostream>

#include"common.h"

using namespace std;
int main(){

	int key = 33333;

	CShmMemory* shm = create_shm_memory(key, CCodeQueue::size(50*1024*1024),0);
	if (NULL == shm){
		return -1;
	}

	CCodeQueue::set_sharedmemory(shm);

	CCodeQueue* queue = new CCodeQueue(50*1024*1024);
	if (NULL == queue){
		return -1;
	}


	char buf[1024];
	int len = sizeof(buf);

	while(true){
		int ret = queue->pop(buf,len);
		if(ret != success || len <= 0){
			usleep(1000);
		}else{
			buf[len] = '\0';
			cout<<buf<<endl;
		}
	}

}
