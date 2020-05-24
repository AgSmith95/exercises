#include <iostream>
#include "header.hpp"

// inspired by "Modern Template Techniques" - Jon Kaleb - Meeting C++ 2019
// https://youtu.be/MLV4IVc4SwI

// See more in "header.hpp"

int main() {
    {
        std::cout << "6+3.5f=" << add(6, 3.5f) << '\n'; // 9.5
        short a = 2;
        int b = 100;
        std::cout << "short(2)+int(100)=" << add(a, b) << '\n'; // 102
    }
    std::cout << '\n';
    {
        std::cout << "is_int<float>::value = " << is_int<float>::value << '\n'; // 0
        std::cout << "is_int<  int>::value = " << is_int<  int>::value << '\n'; // 1
        std::cout << '\n';
        std::cout << "is_int_v<float> = " << is_int_v<float> << '\n'; // 0
        std::cout << "is_int_v<  int> = " << is_int_v<  int> << '\n'; // 1
    }
    std::cout << '\n';
    {
        std::cout << "is_same_v<float, int> = " << is_same_v<float, int> << '\n'; // 0
        std::cout << "is_same_v<  int, int> = " << is_same_v<  int, int> << '\n'; // 1
    }
    std::cout << '\n';
    {
        std::cout << "is_same_v<int, remove_const_t<int const>> = "
                  <<  is_same_v<int, remove_const_t<int const>> << '\n'; // 1
        std::cout << "is_same_v<int const, remove_const_t<int const>> = "
                  <<  is_same_v<int const, remove_const_t<int const>> << '\n'; // 0
    }
    std::cout << '\n';
    {
        // Uncomment to see types in compiler errors
//        char c = 'a';       // error: ‘that_type<char> tType’ has incomplete type
//        name_that_type(c);  // error: ‘that_type<char&> paramType’ has incomplete type


//        char& cr = c;       // error: ‘that_type<char> tType’ has incomplete type
//        name_that_type(cr); // error: ‘that_type<char&> paramType’ has incomplete type


//        char const& cCr = c; // error: ‘that_type<const char> tType’ has incomplete type
//        name_that_type(cCr); // error: ‘that_type<const char&> paramType’ has incomplete type

//        const char& Ccr = c; // error: ‘that_type<char> tType’ has incomplete type
//        name_that_type(Ccr); // error: ‘that_type<char&> paramType’ has incomplete type
    }
    return 0;
}