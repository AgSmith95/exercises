#ifndef VIRTUAL_D_HPP
#define VIRTUAL_D_HPP

#include <iostream>
class D {
public:
    virtual void print() = 0;
    virtual void np_print() {
        std::cout << "D::np_print()\n";
    };
    D() {
        std::cout << "D() calls: ";
        // print(); // undefined reference to `D::print()'
        np_print();
    }
    virtual ~D() {
        std::cout << "~D()\n";
    };
};

class DChild: public D {
public:
    DChild() {
        std::cout << "DChild()\n";
    }
    ~DChild() override {
        std::cout << "~DChild()\n";
    };
    void print() override {
        std::cout << "DChild::print()\n";
    }
    void np_print() override {
        std::cout << "DChild::np_print()\n";
    };
};

#endif //VIRTUAL_D_HPP
