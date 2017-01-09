#include <functional>
#include <iostream>
using namespace std;
#include <pthread.h>
#include <unistd.h>


class MyThread{
public:   

    typedef std::function<void ()> _func;
 
    template<typename Fn, typename... Args>
    static int create_thread(Fn&& fn, Args&&... args){
        _func* f = new _func(std::bind(fn, args...));
        pthread_t id;
        if(pthread_create(&id, NULL, MyThread::run, f) != 0){
            return -1;    
        }
        return 0;
    }
    static void* run(void* args){
        _func* f = (_func*)args;
        (*f)();
    }

};


class Test{

public:
    Test(){
    
    }

    int init(){
         return MyThread::create_thread(&Test::run, this, 1, 2);
    }


    void run(int a, int b){
        std::cout<<a<<" "<<b<<std::endl;
    }

};


int main(){
    
    /*MyThread::create_thread([](int a, int b){
            std::cout<<"aaa"<<endl;
            std::cout<<a<<" "<<b<<endl;
        },1,2
    );*/


    Test obj;
    obj.init();
       

    sleep(10);
}
