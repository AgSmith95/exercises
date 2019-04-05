#ifndef VIRTUAL_INHERITANCE_C_HPP
#define VIRTUAL_INHERITANCE_C_HPP

#include <iostream>

class C {
public:
    virtual void virt(int a = 10) {
        std::cout << "C::virt(" << a << ")\n";
    };
    virtual ~C() = default;
};

class CChild: public C {
public:
    /*virtual keyword is not necessary, but usually added for readability reasons*/
    /*virtual*/ void virt(int a = 20) {   //  Clang-Tidy: Annotate this function with 'override' or (rarely) final
        std::cout << "CChild::virt(" << a << ")\n";
    };
    ~CChild() = default;
};

#endif //VIRTUAL_INHERITANCE_C_HPP
