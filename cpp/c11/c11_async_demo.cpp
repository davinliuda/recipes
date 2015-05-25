#include<iostream>
using namespace std;
#include <unistd.h>
#include <future>
#include <chrono>

class Client{

	int get(int a){
		cout<<"begin processor id:"<<a<<endl;
		sleep(1);
		cout<<"end processor id:"<<a<<endl;
		return a;
	}
};



void test_async(){

	std::future<int> f1 = std::async(std::launch::async, [](){
                cout<<"begin f1"<<endl;
		sleep(5);
                cout<<"end f1"<<endl;
                return 8;
        });


        std::future<int> f2 = std::async(std::launch::async, [](){
		cout<<"begin f2"<<endl;
                sleep(10);
                cout<<"end f2"<<endl;
                return 100;
        });


	cout<<"time1:"<<time(NULL)<<endl;	

	//std::chrono::time_point<std::chrono::system_clock> 
	auto cur_time = std::chrono::system_clock::now();

	
        std::future_status s2 =  f2.wait_until(cur_time + std::chrono::seconds(1));
	//f2.wait_for(std::chrono::milliseconds(1000));

	cout<<"time2:"<<time(NULL)<<endl;

        std::future_status s1 =  f1.wait_until(cur_time + std::chrono::seconds(1));
	//f1.wait_for(std::chrono::milliseconds(1000));

	cout<<"time3:"<<time(NULL)<<endl;

        if(s1 == future_status::timeout || s2 == future_status::timeout){
                std::cout<<"timeout"<<endl;
        }else{
                std::cout << "get result is" << f2.get() << endl;
        }

        cout<<"bye"<<endl;
}


int main(){

	for(int i=0;i<1;i++){
		test_async();
	}
}
