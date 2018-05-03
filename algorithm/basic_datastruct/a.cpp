#include <iostream>
using namespace std;

int main() {
	std::string str = "hello";

	for(int i = 0; i< str.size(); i++){
	
		for(int j =i; j< str.size(); j++) {
			std::cout<<str[j];
		}
		std::cout<<std::endl;
	}
}
