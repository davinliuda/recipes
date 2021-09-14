#ifndef _EPOLL_H
#define _EPOLL_H

#define EVENT_SETSIZE 1024

#define EVENT_NONE 0
#define EVENT_WRITABLE 1
#define EVENT_READABLE 2

typedef struct epollEvent{
    int epfd;
    struct epoll_event events[EVENT_SETSIZE];
} epollEvent_t;

typedef void pfEventFileProc(int fd, void *clientData, int mask)


typedef struct event {
    int mask; 
    pfEventFileProc *proc;
    void *clientData;
}event_t;



typedef struct epollLoop{
	event_t events[EVENT_SETSIZE];
	epollEvent_t epoll_event;	
}epollLoop_t;


epollLoop* epoll_createLoop();
int epoll_closeLoop(epollLoop_t*);
int epoll_register_event(epollLoop_t*,int sfd,int mask,pfEventFileProc,void*);
int epoll_delete_event(epollLoop_t*,int sfd,int mask);
int epoll_get_events(epollLoop_t*,int sfd);
int epoll_main();

#endif
