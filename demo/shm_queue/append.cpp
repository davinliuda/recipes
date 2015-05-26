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

	int i= 0;
	char buf[12];
	while(true){
		int len = sprintf(buf,"%d",i);
		int ret = queue->append(buf,len);
		if(ret != success){
			cout<<"abc"<<endl;
		}else{
			cout<<i<<":"<<len<<endl;
			//usleep(1000);
		}
		i++;
	}
}
