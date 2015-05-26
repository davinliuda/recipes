#include <iostream>
#include <future>
#include <thread>
#include <utility>
#include <deque>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <chrono>
#include <ctime>

using namespace std;

typedef packaged_task<int()> TASK;

#include<pthread.h>

std::mutex mu;

deque<TASK> tasks;


void thread_enter(){

	while(true){
		mu.lock();
		if(tasks.empty()){
			mu.unlock();
			//cout<<"thread:"<<(int)pthread_self()<<endl;
			usleep(100);
			continue;
		}
		auto t = std::move(tasks.front());
		tasks.pop_front();
		mu.unlock();
		t();
		//cout<<"task"<<t()<<endl;
	}
}


std::future<int> maketask(TASK& task){
	std::future<int> f = task.get_future();
        mu.lock();
        tasks.push_back(std::move(task));
        mu.unlock();
	return std::move(f);
}


int waitResult(vector<std::future<int>>& f,int timeoutMS){

	vector<std::future_status> status;

	auto cur_time = std::chrono::system_clock::now();

	for(int i=0;i<f.size();i++){
		std::future_status s = f[i].wait_until(cur_time + std::chrono::milliseconds(timeoutMS));
		status.push_back(std::move(s));
	}
	for(int i=0;i<status.size();i++){
		if(status[i] == future_status::timeout){
			return -1;
		}
	}
	return 0;
}



void processorRequest(){

	TASK task1(
                []() -> int{
                        cout<<"req1........"<<endl;
                        usleep(10000);
                        return 111;
                }
        );

        TASK task2(
                []() -> int{
                        cout<<"req2........"<<endl;
                        usleep(30000);
                        return 222;
                }
        );
	
	std::future<int> f1 = maketask(task1);
	std::future<int> f2 = maketask(task2);


	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	
	//std::cout << "start:" << std::ctime(&start);
	
	vector<std::future<int>> waitEvents;
	waitEvents.push_back(std::move(f1));
	waitEvents.push_back(std::move(f2));



	if(waitResult(waitEvents,50) == -1){
		cout<<"timeout"<<endl;
	}else{
		cout<<"ok"<<endl;
		for(int i=0;i<waitEvents.size();i++){
			cout<<waitEvents[i].get()<<endl;
		}
	}
	
	end = std::chrono::system_clock::now();

	//std::cout << "end:"<<std::ctime(&end);
	
	int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end-start).count();

	std::cout << " elapsed:"<< elapsed <<endl;	
}



int main(){
	vector<thread*> threadpool;
	
	for(int i=0;i<8;i++){
		thread* t = new thread(thread_enter);
		threadpool.push_back(t);
	}	

	std::chrono::time_point<std::chrono::system_clock> start, end;

        start = std::chrono::system_clock::now();
	for(int i=0;i<100;i++){
		processorRequest();
	}
	end = std::chrono::system_clock::now();
	int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>
                             (end-start).count();

        std::cout << "end elapsed:"<< elapsed <<endl;
	
	for(int i=0;i<threadpool.size();i++){
		threadpool[i]->join();
	}

}
