#include <iostream>
#include "A.hpp"    // default "bad" example of using virtual methods without defining destructor as virtual
#include "B.hpp"    // fix of  "bad" example
#include "C.hpp"    // virtual methods and default arguments
#include "D.hpp"    // is pure virtual function in constructor even legit?
#include "F.hpp"    // yes, if you call another function, which calls pure virtual one
#include "G.hpp"    // constructors and destructors of fields in case of  non-virtual destructor

#include "OverrideFinal.hpp" // simple example of virtual/override/final usage

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
    // A.hpp & B.hpp
    {   // Virtual destructors = MUST HAVE, if you have virtual methods
        A *a = new AChild{};
        a->virt();
        delete a;   // only ~A() called
        std::cout << '\n';
        B *b = new BChild{};
        b->virt();
        delete b;   // ~BChild() and ~B() called and object is properly destructed

//        A()
//        AChild()
//        AChild::virt()
//        ~A()

//        B()
//        BChild()
//        BChild::virt()
//        ~BChild()
//        ~B()
    }
    // C.hpp
    std::cout << '\n';
    {   // Virtual methods + default arguments
        C *c = new CChild{};
        c->virt();  //  CChild::virt(10) // despite CChild::virt has default argument 20 and not 10
                    //  happens because 'c' is a pointer to a class 'C' and not to 'CChild'
        ((CChild*)c)->virt();
        dynamic_cast<CChild*>(c)->virt();

//        CChild::virt(10)
//        CChild::virt(20)
//        CChild::virt(20)
    }
    // D.hpp
    std::cout << '\n';
    {
        D *dc = new DChild();
        dc->print();
        delete dc;

//        D() calls: D::np_print()
//        DChild()
//        DChild::print()
//        ~DChild()
//        ~D()
    }
    // F.hpp
    std::cout << '\n';
    {
        // F *f = new FChild();    // no compiler errors, dammit
        // but it causes this:
        //      pure virtual method called
        //      terminate called without an active exception
    }
    // G.hpp
    {   // G.hpp
        G *gc = new GChild();
        gc->f();
        delete gc;

//        G()
//        Field()
//        GChild()
//        GChild::f()
//        ~G()
    }
    // OverrideFinal.hpp
    std::cout << '\n';
    {
        Parent* child = new Child();
        Parent* gchild = new GrChild();
//        Parent* ggchild = new GrGrChild();

        std::cout << child->foo(0) << '\n';
        std::cout << gchild->foo(0) << '\n';
//        std::cout << gchild->foo(0) << '\n';

        delete child;
        delete gchild;
//        delete ggchild;

//        100
//        1000
    }
    return 0;
}