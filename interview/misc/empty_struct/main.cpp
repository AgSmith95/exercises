#include <iostream>

struct A {
    void print() {
        std::cout << "A::print()\n";
    }
};

int main() {
    {
        // A a();  // empty parentheses interpreted as function declaration
        // a.print();  // error: request for member ‘print’ in ‘a’, which is of non-class type ‘A()’
    }
    {
        A a1{}; // {} interpreted as initializer_list, tho
        a1.print();

        A a2;
        a2.print();
    }
    std::cout << "\n";
    return 0;
}