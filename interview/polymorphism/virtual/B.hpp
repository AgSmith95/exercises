#ifndef VIRTUAL_INHERITANCE_B_HPP
#define VIRTUAL_INHERITANCE_B_HPP

#include <iostream>

// Class B has virtual method AND virtual destructor
class B {
public:
    B() {
        std::cout << "B()\n";
    };
    virtual void virt() {
        std::cout << "B::virt()\n";
    };
    virtual ~B() {
        std::cout << "~B()\n";
    };
};

class BChild: public B {
public:
    BChild() { //  Clang-Tidy: Annotate this function with 'override' or (rarely) final
        std::cout << "BChild()\n";
    }
    /*virtual keyword is not necessary, but usually added for readability reasons*/
    /*virtual*/ void virt() {   //  Clang-Tidy: Annotate this function with 'override' or (rarely) final
        std::cout << "BChild::virt()\n";
    }
    ~BChild() { //  Clang-Tidy: Annotate this function with 'override' or (rarely) final
        std::cout << "~BChild()\n";
    }
};

#endif //VIRTUAL_INHERITANCE_B_HPP
