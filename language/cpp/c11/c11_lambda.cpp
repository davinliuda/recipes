#include<iostream>
using namespace std;



int main(){
	int c = 1;
	auto f = [&c](int a,int b){
		sleep(10);
		return c + a + b;
	};
	cout<<f(1,2)<<endl;
}
