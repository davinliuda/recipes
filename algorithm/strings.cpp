#include<iostream>
using namespace std;
#include<string>
#include <assert.h>
#include <string.h>

std::string itoa(int value) {
    std::string buf;
    buf.resize(10);
    int tmp = value >0 ? value : -value;
    int len = 0;
    while(tmp > 0){
        buf[len++] = tmp % 10 + '0';
        tmp = tmp / 10;
    }

    std::cout<<buf<<endl;

    if(value < 0 ){
        buf[len++] = '-';
    }

    for(int i = 0; i <= len / 2; i++){
        int t = buf[i];
        buf[i] = buf[len - 1];
        buf[len -1] = t;
    }    

    return buf;
}


int atoi(const char* ptr) {
    assert(ptr != NULL);
    int value = 0;
    bool is_negative = false;
    const char* base = ptr;
    if(base[0] == '-') {
        base++;
        is_negative = true;
    }

    for(int i = 0; i<strlen(base);i++){
        if(base[i] <'0' || base[i] > '9'){
            break;
        }
        value = value*10 + (base[i] - '0');
    }

    return is_negative ? -value: value;
}


std::string large_mul(const std::string& a, const std::string& b){
    
}


int main(){
    std::string s = itoa(123);
    std::cout<<s.c_str()<<" "<<s.size()<<endl;

    std::cout<<atoi("-1112")<<endl;

}
