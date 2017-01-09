#include<iostream>
using namespace std;
#include <stdio.h>

template<class T>
struct to_string {
};

template<>
struct to_string<int>{
    std::string operator()(const int& obj) const{
        char buf[256];
        snprintf(buf, sizeof(buf), "%d", obj);
        return buf;
    }
};


template<>
struct to_string<long>{
    std::string operator()(const long& obj) const{
        char buf[256];
        snprintf(buf, sizeof(buf), "%lld", obj);
        return buf;
    }
};


int main(){
    std::cout<<to_string<int>()(111)<<std::endl;
    std::cout<<to_string<long>()(11111)<<std::endl;
}
