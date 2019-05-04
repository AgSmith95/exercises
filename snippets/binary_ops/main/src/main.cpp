#include <stdint.h>   // for uint32_t
#include "rotate_right.h"

#include <iostream>
#include <bitset>

int main() {
    uint32_t x = 0b00000001;
    uint32_t y = 0b00000011;
    std::cout << std::bitset<32>(x) << '\n';
    std::cout << std::bitset<32>(y) << '\n';
    std::cout << std::bitset<32>(x^y) << '\n';
    std::cout << '\n';
    std::cout << std::bitset<32>(x << 1) << '\n';
    std::cout << std::bitset<32>(y >> 1) << '\n';
    std::cout << '\n';
    std::cout << std::bitset<32>(rotl32a(y, 31)) << '\n';
    return 0;
}