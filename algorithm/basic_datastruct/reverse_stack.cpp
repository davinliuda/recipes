#include<stack>
#include<iostream>
using namespace std;


void reverse(std::stack<int>& a) {
	
	if (a.empty()) {
		return;
	}

	int tmp = a.top();
	a.pop();
	//std::cout << tmp << " " << std::endl;
	reverse(a);
	
	a.push(tmp);
}


int main() {
	std::stack<int> obj;
	obj.push(1);
	obj.push(4);
	obj.push(2);


	reverse(obj);

	std::cout<<obj.size()<<std::endl;
	while (!obj.empty()) {
		std::cout << obj.top() << " " << std::endl;
		obj.pop();
	}
}
