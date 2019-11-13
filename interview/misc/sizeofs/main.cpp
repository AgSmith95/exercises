#include <iostream>

struct A {
    char c0;
    char C0;
    char C1;
};

struct B {
    char  c0;
    short s;
    char  c1;
    char  c2;
};

struct C {
    char c0;
    int  i;
    char c1;
    char c2;
    char c3;
    char c4;
};

struct D {
    char c0;
    long l;
    char c1;
};

struct E {
    char        c0;
    long double ld;
    char        c1;
};

int main() {
    std::cout << "                  sizeof(char) = " << sizeof(char) << "\n";
    std::cout << "         sizeof(unsigned char) = " << sizeof(unsigned char) << "\n";
    std::cout << "                 sizeof(short) = " << sizeof(short) << "\n";
    std::cout << "        sizeof(unsigned short) = " << sizeof(unsigned short) << "\n";
    std::cout << "                   sizeof(int) = " << sizeof(int) << "\n";
    std::cout << "          sizeof(unsigned int) = " << sizeof(unsigned int) << "\n";
    std::cout << "              sizeof(long int) = " << sizeof(long int) << "\n";
    std::cout << "     sizeof(unsigned long int) = " << sizeof(unsigned long int) << "\n";
    std::cout << "         sizeof(long long int) = " << sizeof(long long int) << "\n";
    std::cout << "sizeof(unsigned long long int) = " << sizeof(unsigned long long int) << "\n";
    std::cout << "                 sizeof(float) = " << sizeof(float) << "\n";
    std::cout << "                sizeof(double) = " << sizeof(double) << "\n";
    std::cout << "           sizeof(long double) = " << sizeof(long double) << "\n";

    std::cout << "\n";

    std::cout << "sizeof(A) = " << sizeof(A) << "\n";
    std::cout << "sizeof(B) = " << sizeof(B) << "\n";
    std::cout << "sizeof(C) = " << sizeof(C) << "\n";
    std::cout << "sizeof(D) = " << sizeof(D) << "\n";
    std::cout << "sizeof(E) = " << sizeof(E) << "\n";
    return 0;
}

/*
OUTPUT (for x86_64):
                   sizeof(char) = 1
         sizeof(unsigned char) = 1
                 sizeof(short) = 2
        sizeof(unsigned short) = 2
                   sizeof(int) = 4
          sizeof(unsigned int) = 4
              sizeof(long int) = 8
     sizeof(unsigned long int) = 8
         sizeof(long long int) = 8
sizeof(unsigned long long int) = 8
                 sizeof(float) = 4
                sizeof(double) = 8
           sizeof(long double) = 16

sizeof(A) = 3
sizeof(B) = 6
sizeof(C) = 12
sizeof(D) = 24
sizeof(E) = 48
 */