#include <iostream>
#include <sstream>

#include "Capture.hpp"

int main() {
    {
        int (*lambda1)(int) = [](int a){    // 1. []
            return a;
        };
        std::cout << lambda1(10) << '\n';
        auto lambda2 = [](int a){           // 1. []
            return a;
        };
        std::cout << lambda2(10) << '\n';
    }
    std::cout << "\n";
    {   // capture list
        two();      // 2.4. [&] and [capture-list with '&' variable]
        three();    // 3.4. [=] and [capture-list with '=' variable]
        fivesix();  // 5.6. [&, capture-list] and [=, capture-list ]
    }
    std::cout << "\n";
    {   // mutable lambdas
        int x{10};
        auto lambda1 = [x](int a) mutable { // tells that lambda can mutate it's local variables
                                            // captured by value [3]
                                            // more stuff here: https://www.youtube.com/watch?v=br4tez2G9eM
            x += a; // impossible without mutable: error: assignment of read-only variable ‘x’
            return x;
        };
        std::cout << lambda1(10) << '\n';
        std::cout << lambda1(10) << '\n';
        std::cout << lambda1(10) << '\n';
    }
    // for more understanding what lambdas are equivalent to use https://cppinsights.io/
    return 0;
}