#ifndef _ASYNC_CLIENT_H_
#define _ASYNC_CLIENT_H_


#define LOG


struct Options{
};

class AsyncClient{
public:
    AsyncClient(EventLoop* loop);
    ~AsyncClient();
    void set_options(std::map<std::string,std::string> options);
    int connect(const std::string& ip, int port);
    int disconnect();
    void stop();
    void send(const void* message, int len);
    void set_connection_callback();
    void set_error_callback();
private:
    EventLoop* loop_;
};

#endif

