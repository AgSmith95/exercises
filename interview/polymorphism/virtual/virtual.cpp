#include <iostream>
#include "A.hpp"
#include "B.hpp"

//class Erroneous {
//public:
//    virtual void pure_virt() = 0;
//    ~Erroneous() = 0; //  error: initializer specified for non-virtual method ‘Erroneous::~Erroneous()’
//};

int main() {
    // <EXAMPLE1> Virtual destructors = MUST HAVE if you have virtual methods
    A* a = new AChild{};
    a->virt();
    std::cout << '\n';
    B* b = new BChild{};
    b->virt();
    std::cout << '\n';
    delete a;   // only ~A() called
    delete b;   // ~BChild() and ~B() called and object is properly destructed
    // </EXAMPLE1>
    std::cout << '\n';
    return 0;
}