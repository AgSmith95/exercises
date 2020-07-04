#ifndef CLASS_TEMPLATE_CPP
#define CLASS_TEMPLATE_CPP

class MyClass {
public:
    MyClass(); // default constructor
    explicit MyClass(int); // constructor with parameters

    ~MyClass(); // destructor

    MyClass(const MyClass&); // copy constructor
    MyClass& operator=(const MyClass&); // copy assignment

    MyClass(MyClass&&) noexcept; // move constructor
    MyClass& operator=(MyClass&&) noexcept; // move assignment
private:
    int* data;
    unsigned size;
};

#endif
