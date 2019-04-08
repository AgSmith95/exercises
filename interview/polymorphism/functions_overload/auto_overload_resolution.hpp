#ifndef FUNCTIONS_OVERLOAD_AUTO_OVERLOAD_RESOLUTION_HPP
#define FUNCTIONS_OVERLOAD_AUTO_OVERLOAD_RESOLUTION_HPP

/**
 *      Stroustrup The C++ Prog. Lang. 4ed:
 * To approximate our notions of what is reasonable, a series of criteria are tried in order:
 *  [1] Exact match; that is, match using no or only trivial conversions (for example, array name
 *      to pointer, function name to pointer to function, and T to const T )
 *  [2] Match using promotions; that is, integral promotions ( bool to int , char to int , short to int ,
 *      and their unsigned counterparts; and float to double
 *  [3] Match using standard conversions (e.g., int to double , double to int , double to long double ,
 *      Derived∗ to Base∗ , T∗ to void∗, int to unsigned int).
 *  [4] Match using user-defined conversions (e.g., double to complex<double>)
 *  [5] Match using the ellipsis "..." in a function declaration.
 *
 *  [X] If two matches are found at the highest level where a match is found, the call is rejected as ambiguous.
 *      The resolution rules are this elaborate primarily to take into account the elaborate C and C++ rules
 *      for built-in numeric types.
 *
 *      The reason to distinguish between conversions and promotions is that we want
 *          to prefer safe promotions, such as char to int , over unsafe conversions, such as int to char.
 */

#include <iostream>

// Auxiliary
class A {
    int data;
public:
    A(): data{65} {};
    int getA() const { return data; };
    operator double() const {   //  Clang-Tidy asks for explicit, but
        return getA();          //  in the example we need implicit conversion
    }                           //  for the overload to work
};
class B: public A {
    /*/
            //  uncomment this and receive:
            //      error: call of overloaded ‘overloaded4(B&)’ is ambiguous
            //          note: candidate: void overloaded4(char)
            //          note: candidate: void overloaded4(double)
    operator int() const {
        return getA();
    }
    //*/
};

class C {
public:
    operator char() const {
        return 'F';
    }
};
// Auxiliary

// [1]
void overloaded1(int a) {
    std::cout << "void overloaded1(int: " << a << ")\n";
}
void overloaded1(char a) {
    std::cout << "void overloaded1(char: " << a << ")\n";
}
void overloaded1(const char* a) {
    std::cout << "void overloaded1(const char*: " << a << ")\n";
}
void overloaded1(double a) {
    std::cout << "void overloaded1(double: " << a << ")\n";
}

// [2]
void overloaded2(int a) {
    std::cout << "void overloaded2(int: " << a << ")\n";
}
void overloaded2(double a) {
    std::cout << "void overloaded2(double: " << a << ")\n";
}
void overloaded2(const char* a) {
    if (a != nullptr) {
        std::cout << "void overloaded2(const char*: " << a << ")\n";
    }
    else {
        std::cout << "void overloaded2(const char*: nullptr)\n";
    }
}

// [3]
void overloaded3(long double a) {
    std::cout << "void overloaded3(long double: " << a << ")\n";
}
/*
void overloaded3(int a) {    // this makes call "overloaded3(double)" ambiguous
    std::cout << "void overloaded3(int: " << a << ")\n";
}
*/
void overloaded3(A* a) {
    std::cout << "void overloaded3(A*: " << a->getA() << ")\n";
}

// [4]
void overloaded4(char a) {
    std::cout << "void overloaded4(char: " << a << ")\n";
}
void overloaded4(double a) {
    std::cout << "void overloaded4(double: " << a << ")\n";
}

#endif //FUNCTIONS_OVERLOAD_AUTO_OVERLOAD_RESOLUTION_HPP
