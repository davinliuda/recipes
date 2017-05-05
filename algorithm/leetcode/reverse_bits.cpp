#include <iostream>
using namespace std;
#include <stdint.h>

uint32_t reverse_bits(uint32_t val) {
    uint32_t res = 0;
    for (int i = 0; i<32; i++) {
        if(val & 1  == 1) {
            res = (res << 1) + 1;
        } else {
            res = res << 1;
        }
        val = val >> 1;
    }
    return res;
}

int main() {
    std::cout<<reverse_bits(123);

}
