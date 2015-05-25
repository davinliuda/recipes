#include<iostream>

using namespace std;


#include<vector>
#include<algorithm>

int main(){

	std::vector<int> a;
	std::vector<int> b;

	for(int i=0;i<10;i++){
		a.push_back(i);
	}

	std::transform(a.begin(),a.end(),std::back_inserter(b),[](int a) -> int {return a;});

	for(auto a : b){
		cout<<a<<endl;
	}


}
