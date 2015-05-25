#include<thread>

#include<iostream>

using namespace std;


void f(int a){
	cout<<a<<endl;
}

int main(){

	std::thread t(f,1);
	t.join();

}
