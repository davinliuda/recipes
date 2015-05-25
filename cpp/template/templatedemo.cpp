#include<iostream>
using namespace std;


template<int a,class T>
void print1(T b){

    cout<<a+b<<endl;
    cout<<a<<b<<endl;
}


int main(){
    print1<5,double>(3);
}


