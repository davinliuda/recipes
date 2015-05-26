#include "gen-cpp/Service.h"  // 替换成你的.h  
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using boost::shared_ptr;
using namespace  ::weibo;

int main()
{
    boost::shared_ptr<TSocket> socket(new TSocket("127.0.0.1", 9090));
     
    //对接nonblockingServer时必须的，对普通server端时用boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TTransport> transport(new TFramedTransport(socket)); 
     
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    ServiceClient client(protocol);
     
    //设置发送、接收、连接超时
    socket->setConnTimeout(1000000);
    socket->setRecvTimeout(1000000);
    socket->setSendTimeout(1000000);
     
    transport->open();
     
    //Response control(1: Request param)

    for(int i=0;i<1;i++){	
	    Request req;
	    req.data = "hello world";
	    Response res;
	    client.control(res,req);
	    printf("client get ret=%s\n",res.data.c_str());
    }
    transport->close();
    return 0;
}
