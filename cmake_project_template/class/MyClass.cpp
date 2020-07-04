#include "MyClass.h"

MyClass::MyClass(): data{nullptr}, size{0} {}

MyClass::MyClass(int s) {
    data = new int[s];
    size = s;
}

MyClass::~MyClass() {
    delete [] data;
    data = nullptr;
    size = 0;
}

MyClass::MyClass(const MyClass& other) {
    data = new int[other.size];
    size = other.size;
}

MyClass& MyClass::operator=(const MyClass& other) {
    if (this != &other) {
        data = new int[other.size];
        size = other.size;
    }
    return *this;
}

MyClass::MyClass(MyClass&& other) noexcept {
    data = other.data;
    size = other.size;

    other.data = nullptr;
    other.size = 0;
}

MyClass& MyClass::operator=(MyClass&& other) noexcept {
    if (this != &other) {
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}
