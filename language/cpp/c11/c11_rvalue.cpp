#include<iostream>
using namespace std;



void test_basic_rvalue(){
    int&& a = 1;
    a = 2;
    cout<<a<<endl;
}



template<typename T>
void test(T&& param){ //&&为universal references时的唯一条件是有类型推断发生
    cout<<param<<endl;//universal references仅仅在T&&下发生，任何一点附加条件都会使之失效，而变成一个右值引用.const T&& 都不是
                        //http://www.cnblogs.com/qicosmos/p/3369940.html
}

void test1(int&& a){
    cout<<a<<endl;
}

int main(){
    test_basic_rvalue();


    int a = 10;
    test(a);//lvalue

    test(10);//rvalue

    test1(10);//rvalue

    test1(a);//complie error
}
