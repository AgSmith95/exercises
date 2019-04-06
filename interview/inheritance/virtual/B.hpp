#ifndef VIRTUAL_INHERITANCE_B_HPP
#define VIRTUAL_INHERITANCE_B_HPP

#include <iostream>

#include <iostream>

class B {
    int data;
public:
    B(): data{} {
        std::cout << "B()\n";
    }
    explicit B(const int& x): data{x} { //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "B(" << data << ")\n";
    }
    int getData() { return data; }
};

class BChild1: virtual public B {
public:
    BChild1() {
        std::cout << "BChild1()\n";
    }
    explicit BChild1(const int& x): B{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "BChild1(" << getData() << ")\n";
    }
};

class BChild2: virtual public B {
public:
    BChild2() {
        std::cout << "BChild2()\n";
    }
    explicit BChild2(const int& x): B{x} {  //  Clang-Tidy: Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
        std::cout << "BChild2(" << getData() << ")\n";
    }
};

class BGrandchild: virtual public BChild1, virtual public BChild2 {
public:
    BGrandchild() {
        std::cout << "BGrandchild()\n";
    }
    explicit BGrandchild(const int& d): B{d} {
        std::cout << "BGrandchild(" << d << ")\n";
    };
    BGrandchild(const int& x, const int& y): BChild1{x}, BChild2{y} {
        std::cout << "BGrandchild(" << x << ',' << y << ")\n";
    };
};

#endif //VIRTUAL_INHERITANCE_B_HPP
