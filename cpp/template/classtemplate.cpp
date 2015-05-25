#include<iostream>
using namespace std;

template<class T>
class Stack{

public:
    Stack(const T& a);
    void print();

private:
    T a;
};


template<class T>
Stack<T>::Stack(const T& a){
    this->a = a;
}


template<class T>
void Stack<T>::print(){
    cout<<a<<endl;
}


int main(){

    Stack<int> obj(12);
    obj.print();

}
