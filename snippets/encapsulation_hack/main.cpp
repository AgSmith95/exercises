#include <iostream>

class A {
public:
    A(int i, long l): I{i}, L{l} {}
    int getI() const { return I; }
    long getL() const { return L; }
private:
    int I;
    long L;
};

int main() {
    A a(5,10);
    std::cout << sizeof(A) << '\n';
    std::cout << sizeof(char) << '\n';
    std::cout << sizeof(int) << '\n';
    std::cout << sizeof(long) << '\n';
    std::cout << "A(" << a.getI() << ',' << a.getL() << ")\n"; // A(5,10)

    // !!! not on every architecture !!!
    // A:   16 bytes =
    //       4 bytes - I
    //       4 bytes - padding
    //       8 bytes - L
    char* hack = (char*)&a;
    *((int*)hack) = 10;
    *((long*)(hack+8)) = 15;
    std::cout << "A(" << a.getI() << ',' << a.getL() << ")\n"; // A(10,15)

    return 0;
}