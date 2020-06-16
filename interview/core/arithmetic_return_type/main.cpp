#include <iostream>
#include "type_name.hpp"

int main() {
    std::cout << 25u - 50 << '\n'; // max unsigned int value - 25 = 4294967271
    std::cout << 0u - 1 << '\n';   // (2^32 - 1) = max unsigned int value = 4294967295

    std::cout << '\n';
    std::cout << 25 - 50u << '\n'; // max unsigned int value - 25 = 4294967271
    std::cout << 25 - 50 << '\n';  // -25

    std::cout << '\n';
    std::cout << type_name<decltype(25)>() << '\n';  // int
    std::cout << type_name<decltype(50)>() << '\n';  // int
    std::cout << type_name<decltype(0u)>() << '\n';  // unsigned int
    std::cout << type_name<decltype(25u)>() << '\n'; // unsigned int
    std::cout << type_name<decltype(50u)>() << '\n'; // unsigned int
    std::cout << type_name<decltype(25u - 50)>() << '\n'; // unsigned int
    std::cout << type_name<decltype(0u - 1)>() << '\n';   // unsigned int
    std::cout << type_name<decltype(25 - 50u)>() << '\n'; // unsigned int
    std::cout << type_name<decltype(25 - 50)>() << '\n';  // int

    std::cout << '\n';
    std::cout << 25u - 50l << '\n'; // -25
    std::cout << type_name<decltype(25u - 50l)>() << '\n'; // long

    return 0;
}