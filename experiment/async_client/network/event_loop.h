#ifndef _EVENTLOOP_H_
#define _EVENTLOOP_H_

class EventLoop{
public:
    enum{
        ReadMask    = 0x1,
        WriteMask   = 0x2,
        PersistMask = 0x4
    };
    
    void run(){
        
    }
    
    void register_handler(int mask, int fd, void* ctx){
        
    }
    void remove_hander(int mask, int fd, void* ctx){
        
    }

private:
    

};



#endif

