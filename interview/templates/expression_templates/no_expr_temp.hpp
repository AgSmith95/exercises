#ifndef PPP_INHERITANCE_NO_EXPR_TEMP_HPP
#define PPP_INHERITANCE_NO_EXPR_TEMP_HPP

#include <vector>
#include <iostream>
#include <assert.h>

//  usual vector operator+ implementation

class Vect {
    std::vector<double> elems;

public:
    explicit Vect(size_t n) : elems(n) {
        std::cout << "Vect(" << n << ")\n";
    }

    double &operator[](size_t i)      { return elems[i]; }
    double operator[](size_t i) const { return elems[i]; }
    size_t size()               const { return elems.size(); }
};

Vect operator+(Vect const &u, Vect const &v) {
    assert(u.size() == v.size());
    Vect sum(u.size());
    for (size_t i = 0; i < u.size(); i++) {
        sum[i] = u[i] + v[i];
    }
    return sum;
}

#endif //PPP_INHERITANCE_NO_EXPR_TEMP_HPP
