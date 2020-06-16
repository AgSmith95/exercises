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
    // As a general rule, you should never call virtual functions in constructors or destructors.
    // If you do, those calls will never go to a more derived class than the currently
    // executing constructor or destructor.
    // In other words, during construction and destruction, virtual functions aren't virtual.
    return 0;
}
