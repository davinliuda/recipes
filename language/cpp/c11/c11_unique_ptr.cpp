#include<memory>
#include<iostream>
using namespace std;

class Test{
public:
    ~Test(){
        cout<<"~Test"<<endl;
    }
};

void test(){

    unique_ptr<Test> a(new Test());
  
}


int main(){
    test();
}

