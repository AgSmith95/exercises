#include <iostream>

#define LIGHT 299792458 // define variable
#define ENERGY(mass) ((mass)*LIGHT*LIGHT)   // define function
#define SET_BIT(value, bit, num) ((value) | (bit) << (num))   // somewhat standard question

#define str(x) #x           // stringification
#define concat(x,y) x##y    // concatenation

int main() {
    std::cout << "==== ==== Defining object: \n";
    {
        std::cout << "#define LIGHT " << LIGHT << '\n';
    }
    std::cout << "==== ==== Defining function: \n";
    {
        int mass = 2;
        std::cout << "ENERGY(" << mass << ") = " << ENERGY(mass) << '\n';

        // SET_BIT
        unsigned value = 0; // because of Clang-Tidy
        unsigned bit = 1;   // signed int in bitwise operator
        for (unsigned i = 0; i <= 7; ++i) {
            std::cout << SET_BIT(value, bit, i) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "==== ==== #ifdef/#if/defined(): \n";
    {
#ifdef _GLIBCXX_IOSTREAM
        std::cout << "_GLIBCXX_IOSTREAM defined\n";
#endif
#if defined(LIGHT) && LIGHT > 100
        std::cout << "#defined LIGHT && LIGHT > 100\n";
#endif
    }
    std::cout << "==== ==== #undef macro: \n";
    {
#undef LIGHT
#ifdef LIGHT
        std::cout << "LIGHT defined\n";
#elif defined(DARK)
        std::cout << "DARK defined\n";
#else
        std::cout << "LIGHT undefined\n";
#endif
    }
    std::cout << "==== ==== Default macro: \n";
    {
        std::cout << "Current date / time : " << __DATE__ << " / " << __TIME__ << '\n';
        std::cout << __FILE__ << ":    " << __func__ << ':' << __LINE__ << '\n';
        std::cout << "__STDC__ " << __STDC__ << '\n';
    }
    std::cout << "==== ==== Stringification: \n";
    {
        std::cout << str(12) << '\n';
        std::cout << str(0.3) << '\n';
        std::cout << str(12+0.3) << '\n';
    }
    std::cout << "==== ==== Concatenation: \n";
    {
        std::cout << concat(1,2) << '\n';
        std::cout << concat(2+2,3+3) << '\n';   // 28, because "2+23 +3"
        // see concat.cpp / concat.i
        // concat.i = g++ -std=c++11 -E concat.cpp > concat.i
    }
    std::cout << "\n";
    return 0;
}