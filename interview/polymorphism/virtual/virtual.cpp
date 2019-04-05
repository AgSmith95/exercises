#include <iostream>
#include "A.hpp"    // default "bad" example of using virtual methods without defining destructor as virtual
#include "B.hpp"    // fix of  "bad" example
#include "C.hpp"    // virtual methods and default arguments

//class Erroneous { // example showing that in order to "=0" a destructor it needs to be virtual, at least
//public:
//    virtual void pure_virt() = 0;
//    ~Erroneous() = 0; //  error: initializer specified for non-virtual method ‘Erroneous::~Erroneous()’
//};

//class E { //  example of inability to instantiate class with pure virtual method
//public:
//    virtual ~E() = 0;
//};
//E e;  // error: cannot declare variable ‘e’ to be of abstract type ‘E’
//      // note:   because the following virtual functions are pure within ‘E’:
//      // note:   virtual E::~E()

int main() {
    {   // Virtual destructors = MUST HAVE, if you have virtual methods
        A *a = new AChild{};
        a->virt();
        delete a;   // only ~A() called
        std::cout << '\n';
        B *b = new BChild{};
        b->virt();
        delete b;   // ~BChild() and ~B() called and object is properly destructed
    }
    std::cout << '\n';
    {   // Virtual methods + default arguments
        C *c = new CChild{};
        c->virt();  //  CChild::virt(10) // despite CChild::virt has default argument 20 and not 10
                    //  happens because 'c' is a pointer to a class 'C' and not to 'CChild'
        ((CChild*)c)->virt();
        dynamic_cast<CChild*>(c)->virt();
    }
    std::cout << '\n';
    return 0;
}