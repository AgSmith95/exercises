#include <iostream>

#include <type_name.hpp>

void foo(int i, double d) {
    std::cout << "foo(int " << i << ", double " << d << ")\n";
}

int main() {
    // case 3 - neither ptr nor ref
    auto x = 27;        // x
    // case 3
    const auto cx = x;  // const int
    // case 1
    const auto& rx = x; // const int&
    std::cout << type_name<decltype(x)>() << '\n';
    std::cout << type_name<decltype(cx)>() << '\n';
    std::cout << type_name<decltype(rx)>() << '\n';
    std::cout<< '\n';
    // case 2: universal ref
    auto&& urx = x;     // int&
    auto&& urcx = cx;   // const int&
    auto&& urv = 27;    // int&&
    std::cout << type_name<decltype(urx)>() << '\n';
    std::cout << type_name<decltype(urcx)>() << '\n';
    std::cout << type_name<decltype(urv)>() << '\n';
    std::cout<< '\n';
    const char str[] = "Hello, world!"; // const char [14]
    auto astr = str;    // const char*
    auto& arstr = str;  // const char [14]&
    std::cout << type_name<decltype(str)>() << '\n';
    std::cout << type_name<decltype(astr)>() << '\n';
    std::cout << type_name<decltype(arstr)>() << '\n';
    std::cout<< '\n';
    auto af = foo;      // void (*)(int, double)
    auto& arf = foo;    // void (int, double)&
    std::cout << type_name<decltype(af)>() << '\n';
    std::cout << type_name<decltype(arf)>() << '\n';
}
