#include<functional>
#include<iostream>


class Test{
public:
    void print(){
        std::cout<<"print"<<std::endl;
    }

    void print1(int a){
        std::cout<<"hello world:"<<a<<std::endl;
    }

    static void print2(int b){
        std::cout<<"print2:"<<b<<std::endl;
    }
};


int main(){

    Test obj;

    auto p = std::bind(&Test::print, obj);

    p();

    auto p1 = std::bind(&Test::print1, obj, std::placeholders::_1);
    
    p1(1);

    auto p2 = std::bind(&Test::print2, std::placeholders::_1);

    p2(2);
}
