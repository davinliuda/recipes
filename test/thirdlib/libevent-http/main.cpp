#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/http.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
       #include <fcntl.h>
#include<iostream>
using namespace std;


void generic_handler(struct evhttp_request *req, void *arg)
{
    struct evbuffer *buf = evbuffer_new();
    if(!buf){
        puts("failed to create response buffer \n");
        return;
    }

    evbuffer_add_printf(buf, "Server Responsed. Requested: %s\n", evhttp_request_get_uri(req));
    evhttp_send_reply(req, HTTP_OK, "OK", buf);
    evbuffer_free(buf);
}



int httpserver_bindsocket(int port, int backlog) {
  int r;
  int nfd;
  nfd = socket(AF_INET, SOCK_STREAM, 0);
  if (nfd < 0) return -1;
 
  int one = 1;
  r = setsockopt(nfd, SOL_SOCKET, SO_REUSEADDR, (char *)&one, sizeof(int));
 
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);
 
  r = bind(nfd, (struct sockaddr*)&addr, sizeof(addr));
  if (r < 0) return -1;
  r = listen(nfd, backlog);
  if (r < 0) return -1;
 
  int flags;
  if ((flags = fcntl(nfd, F_GETFL, 0)) < 0
      || fcntl(nfd, F_SETFL, flags | O_NONBLOCK) < 0)
    return -1;
 
  return nfd;
}


int main(int argc, char* argv[])
{

    short          http_port = 8081;
    char          *http_addr = "0.0.0.0";

    struct event_base * base = event_base_new();

    struct evhttp * http_server = evhttp_new(base);
    if(!http_server)
    {
        return -1;
    }

    int nfd = httpserver_bindsocket(http_port,10240);

    int ret = evhttp_accept_socket(http_server, nfd);
    if(ret!=0){
	perror("aa");
	return -1;
    }	
    

    //ret = evhttp_bind_socket(http_server,http_addr,http_port);
    //if(ret!=0)
    //{
     //   return -1;
    //}

    evhttp_set_cb(http_server,"/abc",generic_handler, NULL);

    printf("http server start OK! \n");

    event_base_dispatch(base);

    evhttp_free(http_server);

    return 0;
}
