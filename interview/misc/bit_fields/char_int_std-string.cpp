// g++ -std=c++17 char_int_std-string.cpp -o ciss

#include <iostream>
#include <string>

struct S {
    char a;
    int b : 5;
    int c : 11,
          : 0,
        d : 8;
    int e;
    double f;
    std::string g;
};

int main() {
    S s;
    // std::cout << &s.e - &s.a << '\n';
    /*
    error: invalid operands of types 'int*' and 'char*' to binary 'operator-'
      |     std::cout << &s.e - &s.a << '\n';
      |                  ~~~~ ^ ~~~~
      |                  |      |
      |                  int*   char*
    */
    std::cout << &s.e - (int*)&s.a << '\n';     // 3
    std::cout << (char*)&s.e - &s.a << '\n';    // 12
    
    std::cout << '\n';

    s.b = 0b00101;
    s.c = 0b00000001011;
    s.d = 0b00001000;

    std::cout << s.b << '\n';
    std::cout << s.c << '\n';
    std::cout << s.d << '\n';
}
