#include <stdint.h>   // for uint32_t
#include <assert.h>
#include "rotate_right.h"

//#include <iostream>
//#include <bitset>

int main() {
    //std::cout << std::bitset<32>(rotl32a(0x00000001, 1)) << '\n';
    assert(rotl32a(0x80000000, 1) == 0x00000001);
    assert(rotl32a(0x80000001, 1) == 0x00000003);
}