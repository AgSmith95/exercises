#ifndef VIRTUAL_D_HPP
#define VIRTUAL_D_HPP

#include <iostream>
class D {
public:
    virtual void print() = 0;
    D() {
        std::cout << "D::D(); ";
        // print(); // undefined reference to `D::print()'
    }
};

class DChild: public D {
public:
    void print() override {
        std::cout << "DChild::print()\n";
    }
};

#endif //VIRTUAL_D_HPP
