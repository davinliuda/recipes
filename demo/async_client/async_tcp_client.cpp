#include"async_client.h"


class NetBuffer{
    
};



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
};

class TcpConnector{
public:
    TcpConnector(EventLoop* event_loop): fd_(0), event_loop_(event_loop){
        
    }
    ~TcpConnector(){
        
    }
    
    int open(const std::string& ip, int port, Options options){
        if(fd_ != 0){
            LOG(ERROR, "");
            return -1;
        }
        fd_ = socket(AF_INET, SOCK_STREAM, 0);
        if(fd_ != 0){
            LOG(ERROR, "open socket error");
            return -1;
        }
        event_loop_.register_handler(this);
    }
    
    int close(){
        
    }
    void on_read(){
        
    }
    void on_connected(){
        
    }
    
    void on_write(){ 
        
    }
    
    int write(const void* msg, int len){
        
    }
private:
    EventLoop* event_loop_;
    NetBuffer send_bufs_;      
    int fd_;
};


void AsyncClient::set_options(std::map<std::string,std::string> options){
    
}

void AsyncClient::connect(const std::string& ip, int port){
    
}


void AsyncClient::disconnect(){
    
}

void AsyncClient::stop(){
    
}

void AsyncClient::set_read_callback(){
    
}

void AsyncClient::set_connected_callback(){
    
}
