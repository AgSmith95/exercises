#include <iostream>

class Parent {
public:
    virtual ~Parent() {
        method(); // clang-tidy: Do not invoke virtual member functions from destructor
    }
    virtual void method() {
        std::cout << "Parent\n";
    }
};

class Child: public Parent {
public:
    ~Child() override {
        method(); // clang-tidy: Do not invoke virtual member functions from destructor
    }
    void method() override {
        std::cout << "Child\n";
    }
};

int main() {
    Parent* child = new Child();    // Child
    child->method();                // Child
    delete child;                   // Parent
    return 0;
}
