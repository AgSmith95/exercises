#ifndef VIRTUAL_INHERITANCE_A_HPP
#define VIRTUAL_INHERITANCE_A_HPP

#include <iostream>

// Class A has virtual method but doesn't have virtual destructor
class A {
public:
    A() {
        std::cout << "A()\n";
    }
    virtual void virt() {
        std::cout << "A::virt()\n";
    };
    ~A() {
        std::cout << "~A()\n";
    };
};

class AChild: public A {
public:
    AChild() {
        std::cout << "AChild()\n";
    }
    /*virtual keyword is not necessary, but usually added for readability reasons*/
    /*virtual*/ void virt() {   //  Clang-Tidy: Annotate this function with 'override' or (rarely) final
        std::cout << "AChild::virt()\n";
    };
    ~AChild() {
        std::cout << "~AChild()\n";
    }
};

#endif //VIRTUAL_INHERITANCE_A_HPP
