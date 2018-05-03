#include "server.h"

class MyService : public EchoService {
public:
	virtual void Foo(::google::protobuf::RpcController* controller,
			const ::FooRequest* request,
			::FooResponse* response,
			::google::protobuf::Closure* done) {
		
	}
};

int main() {
	
	MyService my_service;

	RpcSvr rpc_svr;

	rpc_svr.RegisterService(&my_service);

}
