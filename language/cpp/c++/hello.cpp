#include<iostream>
using namespace std;
#include<typeinfo>

class A{
public:
    A(){
        a = 22;
    }
    virtual void test(){
        std::cout<<"test22"<<endl;
    }
    int a;
};

class B : public A{
public:
    B(){
        a = 11;
    }
    int a;
    virtual void test(){
        std::cout<<"test11"<<endl;
    }
};

int main(){

    B b;
    A* a = &b;
    
    printf("%p,%p", a, &b);

    //std::cout<<typeid(b).name()<<endl;
    //a->test();
}
