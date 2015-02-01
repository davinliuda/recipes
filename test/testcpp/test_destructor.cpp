#include<iostream>
using namespace std;


class Test{
public:
	virtual ~Test(){
		cout<<"Test"<<endl;
	}
};


class TestA{
public:
	virtual ~TestA(){
		cout<<"TestA"<<endl;
	}
};


class TestB : public Test,public TestA{
public:
	virtual ~TestB(){
		cout<<"TestB"<<endl;
	}
	int c;
};


int main(){
	Test* obj = new TestB();

	delete obj;
}
