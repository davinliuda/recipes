#include"countdownlatch.h"
#include <unistd.h>
#include<iostream>
using namespace std;

void* test_thread(void* arg){
    CountDownLatch* obj = (CountDownLatch*)arg;
    sleep(5);
    cout<<"thread over"<<obj->getcount()<<endl;
    //obj->countdown();
}

int main(){
    CountDownLatch obj(10);
    for(int i=0; i< 10; i++)
    {
        pthread_t id;
        pthread_create(&id, NULL, test_thread, &obj);
    }
    timeval val;
    val.tv_sec = 10;
    val.tv_usec = 0;
    obj.wait(&val);
    cout<<"over"<<endl; 
}
