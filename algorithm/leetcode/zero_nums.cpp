#include <iostream>
using namespace std;
#include <stdint.h>

int zero_nums(uint32_t n) {
    int sum = 0;
    while (n != 0) {
        sum = sum + (n & 1);
        n = n >> 1;
        std::cout<<n<<std::endl;
    }
    return sum;
}

int main() {
    std::cout<<zero_nums(111);

}
