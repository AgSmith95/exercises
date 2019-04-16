#ifndef LRVALUES_A_HPP
#define LRVALUES_A_HPP

#include<iostream>

struct A
{
    A() { std::cout << "A()\n"; }
    A(const A&) { std::cout << "A(const A&)\n"; }
    A(A&&) noexcept { std::cout << "A(A&&)\n"; }

    ~A() { std::cout << "~A()\n"; }

    void use() const {};
};


void no_pf(A &&a)
{
    std::cout << "no_pf(A&& a)\n";
    A b(a); // not using perfect forwarding
    b.use();
}

void pf(A &&a)
{
    std::cout << "pf(A&& a)\n";
    A b(std::forward<A>(a)); // not using perfect forwarding
}

#endif //LRVALUES_A_HPP
