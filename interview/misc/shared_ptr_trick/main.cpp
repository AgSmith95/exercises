#include <iostream>
#include <memory>

class A {
public:
    A() {
        std::cout << "A()\n";
    }
    ~A() {
        std::cout << "~A()\n";
    }
};

int main() {
    {
        A *a = new A();
        std::shared_ptr<A> spa1(a);
        std::shared_ptr<A> spa2(a);
    }
    return 0;
}

/**

Output:
 A()
~A()
~A()
free(): double free detected in tcache 2

 */