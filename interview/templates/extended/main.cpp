#include <iostream>
#include "header.hpp"

// inspired by "Modern Template Techniques" - Jon Kaleb - Meeting C++ 2019
// https://youtu.be/MLV4IVc4SwI

int main() {
    {
        std::cout << "6+3.5f=" << add(6, 3.5f) << '\n';
        short a = 2;
        int b = 100;
        std::cout << "short(2)+int(100)=" << add(a, b) << '\n';
    }
    std::cout << '\n';
    {
        std::cout << "is_int<float>::value = " << is_int<float>::value << '\n';
        std::cout << "is_int<  int>::value = " << is_int<  int>::value << '\n';
        std::cout << '\n';
        std::cout << "is_int_v<float> = " << is_int_v<float> << '\n';
        std::cout << "is_int_v<  int> = " << is_int_v<  int> << '\n';
    }
    std::cout << '\n';
    {
        std::cout << "is_same_v<float, int> = " << is_same_v<float, int> << '\n';
        std::cout << "is_same_v<  int, int> = " << is_same_v<  int, int> << '\n';
    }
    return 0;
}