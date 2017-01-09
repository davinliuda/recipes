#include<iostream>
using namespace std;


//碰到ponitor就error
/*
template <class T>
struct MyIter {
    typedef T value_type; 
    T* ptr;
    MyIter(T* p = 0) : ptr(p) {}
    T& operator*() const { return *ptr; }
};


template <class I>
typename I::value_type func(I iter) {
    return *iter;
}

int main(){
    int i  =10;
    cout<<func(MyIter<int>(&i))<<endl;
}*/




template <class T>
struct MyIter {
    typedef T value_type; 
    T* ptr;
    MyIter(T* p = 0) : ptr(p) {}
    T& operator*() const { return *ptr; }
};

template<typename T>
struct iterator_traits {
    typedef typename T::value_type value_type;
};


template <class T>
struct iterator_traits<T*> {
    typedef typename T* value_type;
};


template <class I>
iterator_traits<I>::value_type func(I iter) {
    return *iter;
};


int main() {
    int i = 10;
    cout<<func(i)<<endl;
}
