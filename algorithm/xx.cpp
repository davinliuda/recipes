#include <string.h>
#include <iostream>
using namespace std;

int main() {
    char s[] = "1234567890";
    char* p1 = s;
    char* p2 = s+2;
    //std::cout<<(char*)memcpy(p2, p1, 5)<<std::endl;
    std::cout<<(char*)memmove(p2, p1, 5)<<std::endl;
}
