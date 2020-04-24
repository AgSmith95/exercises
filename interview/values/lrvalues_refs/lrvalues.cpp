#include <iostream>
#include "X.hpp"
#include "A.hpp"

/**
 *  identity - other word for "variable's name"
 *
 *  lvalues - has identity, but cannot be moved
 *  rvalues - temporary objects, which can (and should) be moved
 * prvalues - like rvalues, but don't have identity
 *
 */

/**
 * [1] & && = &
 * [2] && & = &
 * [3] && && = &&
 */

int main() {
    std::cout << "1\n";
    {
        X lvalue{};
        X &&rvalue_ref{};

        lvalue = rvalue_ref; // X copy assigned
//        X()
//        X()
//        X copy assigned
    }
    std::cout << "\n2\n";
    {
        X &&rvalue_ref{};
        X lvalue{rvalue_ref}; // X copy constructed
        lvalue.use();

//        X()
//        X copy constructed
    }
    std::cout << "\n3\n";
    {
        X lvalue{};
        X &&rvalue_ref{};

        lvalue = std::move(rvalue_ref); // X move assigned

//        X()
//        X()
//        X move assigned
    }
    std::cout << "\n4\n";
    {
        X &&rvalue_ref{};
        X lvalue{std::move(rvalue_ref)}; // X move constructed
        lvalue.use();

//        X()
//        X move constructed
    }
    std::cout << "\n5\n";
    {
        A a;
        no_pf(std::move(a));

//        A()
//        no_pf(A&& a)
//        A(const A&)
//        ~A()
//        ~A()
    }
    std::cout << "\n6\n";
    {
        A a;
        pf(std::move(a));

//        A()
//        pf(A&& a)
//        A(A&&)
//        ~A()
//        ~A()
    }

    // see also perfect forwarding
    return 0;
}