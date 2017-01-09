#include <string.h>
#include<string>
using namespace std;
#include<iostream>

template<class T>
struct IsPodType{
    enum{
        yes = 0
    };
};


#define IS_POD_TYPE(type, is_pod_type) \
template<>                             \
struct IsPodType<type>{                \
    enum{                              \
        yes = is_pod_type              \
    };                                 \
};                                     


IS_POD_TYPE(int, 1)


template<class T>
void copy(T a, T b) {
    if(IsPodType<T>::yes == 1){
        std::cout<<"is_pod_type"<<std::endl;
        memcpy(&a, &b, sizeof(T));
    }else{
        std::cout<<"not_pod_type"<<std::endl;
        a = b;   
    }
}


int main() {
    std::string a = "abcdef";
    std::string b;
   
    copy(a, b); 
    std::cout<<a<<" "<<b<<std::endl;
} 
