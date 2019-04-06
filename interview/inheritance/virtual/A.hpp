#ifndef VIRTUAL_INHERITANCE_A_HPP
#define VIRTUAL_INHERITANCE_A_HPP

#include <iostream>

// Class A has virtual method but doesn't have virtual destructor
class A {
    int data;
public:
    A(): data{} {
        std::cout << "A()\n";
    }
    explicit A(const int& x): data{x} { //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "A(" << data << ")\n";
    }
    int getData() { return data; }
};

class AChild1: public A {
public:
    AChild1() {
        std::cout << "AChild1()\n";
    }
    explicit AChild1(const int& x): A{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "AChild1(" << getData() << ")\n";
    }
};

class AChild2: public A {
public:
    AChild2() {
        std::cout << "AChild2()\n";
    }
    explicit AChild2(const int& x): A{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "AChild2(" << getData() << ")\n";
    }
};

class AGrandchild: public AChild1, public AChild2 {
public:
    AGrandchild() {
        std::cout << "AGrandchild()\n";
    }
    AGrandchild(const int& x, const int& y): AChild1{x}, AChild2{y} {
        std::cout << "AGrandchild(" << x << ',' << y << ")\n";
    };
};

#endif //VIRTUAL_INHERITANCE_A_HPP
