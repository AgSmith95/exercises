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
    {
        X lvalue{};
        X &&rvalue_ref{};

        lvalue = rvalue_ref; // X copy assigned
    }
    std::cout << "\n";
    {
        X &&rvalue_ref{};
        X lvalue{rvalue_ref}; // X copy constructed
        lvalue.use();
    }
    std::cout << "\n";
    {
        X lvalue{};
        X &&rvalue_ref{};

        lvalue = std::move(rvalue_ref); // X move assigned
    }
    std::cout << "\n";
    {
        X &&rvalue_ref{};
        X lvalue{std::move(rvalue_ref)}; // X move constructed
        lvalue.use();
    }
    std::cout << "\n";
    {
        A a;
        no_pf(std::move(a));
    }
    std::cout << "\n";
    {
        A a;
        pf(std::move(a));
    }

    // see also perfect forwarding
    return 0;
}