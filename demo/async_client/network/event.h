#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

class Event 
{
    const int fd_;
    EventLoop* loop_;
 
public:

    virtual int Open();
    virtual int Close();

    virtual void HandleInput();
    virtual void HandleOutput();
    virtual void HandleTimeout(void * pTimerID);
    virtual void HandleClose();
};


#endif

