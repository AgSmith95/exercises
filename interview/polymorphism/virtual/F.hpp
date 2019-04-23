#ifndef VIRTUAL_F_HPP
#define VIRTUAL_F_HPP

#include <iostream>

class F {
public:
    F() {
        std::cout << "F()\n";
        call_pure();    // you should be completely out of your mind to do such things
    }
    virtual ~F() {
        std::cout << "~F()\n";
    };
    virtual void pure() = 0;
    virtual void call_pure() {  // you should be completely out of your mind to do such things
        std::cout << "F::call_pure()\n";
        pure();
    }
};

class FChild: public F {
public:
    void pure() override {
        std::cout << "FChild::pure()\n";
    }
};

#endif //VIRTUAL_F_HPP
