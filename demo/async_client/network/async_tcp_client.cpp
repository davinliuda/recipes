#include"async_client.h"

class TcpConnector : public EventHandler
{
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
    AsyncClient* client_;
    EventLoop* event_loop_;
    Event* event_;
    NetBuffer send_buf_;      
    NetBuffer recv_buf_;
    int fd_;
};



AsyncClient::AsyncClient(EventLoop* loop){
    
}

AsyncClient::~AsyncClient(){
     
}

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
