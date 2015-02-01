#thrift -r --gen cpp stu.thrift 

g++ -I/usr/local/thrift/include/ gen-cpp/Serv.cpp gen-cpp/Serv_server.skeleton.cpp gen-cpp/stu_types.cpp gen-cpp/stu_constants.cpp -L/usr/local/thrift/lib/ -lthrift -lthriftnb -I/usr/local/boost/include/ -L/usr/local/boost/lib/ -lboost_thread -L/usr/local/libevent/lib/ -levent -I/usr/local/libevent/include/ 
