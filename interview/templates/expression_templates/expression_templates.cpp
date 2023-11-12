#include <iostream>
#include "no_expr_temp.hpp"
#include "expr_temp.hpp"

int main() {
    {   //  without expression templates
        Vect a{10}, b{10}, c{10};
        Vect x = a + b + c;
    }
    std::cout << '\n';
    {
        Vec a{10,20,30,40,50},
            b{10,20,30,40,50},
            c{10,20,30,40,50};
        Vec x = a + b + c;
        std::cout << "{ ";
        for (size_t i = 0; i < x.size(); ++i) {
            std::cout << x[i] << " ";
        }
        std::cout << "}\n";
    }
    std::cout << '\n';
    return 0;
}