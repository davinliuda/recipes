#include<future>

#include <iostream>
#include <future>
#include <thread>


using namespace std;


class Client{
public:
	int get(){
		return 1;
	}
};


std::function<void()> f2
 
int main()
{

	Client client;

	std::packaged_task<int()> task(client.get());
	std::future<int> result = task.get_future();
	std::thread(std::move(task)).detach();
	std::cout << "Waiting...";
	result.wait();
	std::cout << "Done!\nResult is " << result.get() << '\n';
}
