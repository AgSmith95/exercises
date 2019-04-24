#include <iostream>

class A {
public:
    A() { std::cout << "A()\n"; }
    ~A() { std::cout << "~A()\n"; }
};
class B {
public:
    B() { std::cout << "B()\n"; }
    ~B() { std::cout << "~B()\n"; }
};
class C {
public:
    C() { std::cout << "C()\n"; }
    ~C() { std::cout << "~C()\n"; }
};
class D {
public:
    D() { std::cout << "D()\n"; }
    ~D() { std::cout << "~D()\n"; }
};

class Test: public A, B {
    C c;
    D d;
public:
    Test() { std::cout << "Test()\n"; }
    ~Test() { std::cout << "~Test()\n"; }
};

int main() {
    {
        Test t;
    }
    std::cout << "\n";
    return 0;
}