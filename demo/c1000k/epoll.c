#include"epoll.h"
#include <sys/epoll.h>


epollLoop* epoll_createLoop(){
	epollLoop_t* epollLoop = (epollLoop_t*)malloc(epollLoop_t);
	epollLoop->efd = -1;
	if(!epollLoop){
		return NULL;
	}
	epollLoop->efd = epoll_create(1024);
	if(epollLoop->efd == -1){
		free(epollLoop);
		return NULL;
	}
	return epollLoop;
}


int epoll_closeLoop(epollLoop_t* epollLoop){
	if(!epollLoop){
		return -1;
	}
	if(epollLoop->efd != -1){
		close(epollLoop->efd);
	}
	free(epollLoop);
	return 0;
}


int epoll_register_event(epollLoop_t* eventLoop,int sfd,int mask,pfEventFileProc* proc,void* clientData){
	if(sfd >= EVENT_SETSIZE){
		return -1;
	}
	int op = eventLoop->events[sfd].mask == EVENT_NONE?
            EPOLL_CTL_ADD : EPOLL_CTL_MOD;
	struct epoll_event ev;
	ev.events = 0;
	if (mask & READABLE) ev.events |= EPOLLIN;
    	if (mask & WRITABLE) ev.events |= EPOLLOUT;
    	ev.data.fd = sfd;
	if (epoll_ctl(eventLoop->epfd,op,sfd,&ev) == -1){
	 	return -1;
	}
	eventLoop->events[sfd].mask |= mask;
	eventLoop->events[sfd].proc = proc;
	eventLoop->events[sfd].clientData = clientData;
	return 0;
}

int epoll_delete_event(epollLoop_t* eventLoop,int sfd,int delmask){
	if(sfd >= EVENT_SETSIZE){
		return -1;
	}
	int mask = eventLoop->events[sfd].mask & (~delmask);
	struct epoll_event ev;
	ev.events = 0;
	if (mask & READABLE) ev.events |= EPOLLIN;
        if (mask & WRITABLE) ev.events |= EPOLLOUT;	
	ev.data.fd = sfd;
	if (mask != AE_NONE) {
        	epoll_ctl(eventLoop->epfd,EPOLL_CTL_MOD,sfd,&ev);
    	} else {
		epoll_ctl(eventLoop->epfd,EPOLL_CTL_DEL,sfd,&ev);
	}
	return 0;
}

int epoll_get_events(epollLoop_t*,int sfd){
	
}

int epoll_main(){
}
