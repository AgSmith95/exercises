#include <iostream>
#include "auto_overload_resolution.hpp"

int main() {
    {   // Automatic Overload Resolution
        {   //  [1] Exact match
            int i{1};
            char c{'F'};
            const char* s = "hello";
            double d{0.01};

            overloaded1(i);
            overloaded1(c);
            overloaded1(s);
            overloaded1(d);
        }
        std::cout << '\n';
        {   //  [2] Match using promotions
            short s{2};
            float f{0.2};

            overloaded2(s);
            overloaded2(f);
            overloaded2(nullptr);
        }
        std::cout << '\n';
        {   //  [3] Match using standard conversions
            double d = 12345.6789;
            B *b = new B{};

            overloaded3(d);
            overloaded3(b);
            //overloaded3((void*)b);    //  error: invalid conversion from ‘void*’ to ‘A*’ [-fpermissive]

            delete b;
        }
        std::cout << '\n';
        {   //  [4] Match using user-defined conversions
            A a;
            B b;
            C c;

            overloaded4(a);
            overloaded4(b);
            overloaded4(c);
        }
        std::cout << '\n';
        {   // [5] Match using the ellipsis
            //TODO: implement example for "[5] Match using the ellipsis"
        }
    }
    return  0;
}
