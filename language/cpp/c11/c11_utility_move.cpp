#include<utility>
#include<iostream>
using namespace std;
#include<string>



int main(){
	std::string a = "aaaa";
	std::string b = std::move(a);
	cout<<b<<endl;
}
