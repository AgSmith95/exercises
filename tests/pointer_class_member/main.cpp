#include <iostream>
#include <iomanip>

class A {
private:
    int *data = nullptr;
public:
    A(int* a): data{a} {};
    void show() {
        std::cout << "data = " << std::hex << data << '\n';
    }

    int* getData() {
        return data;
    }
};

int main() {
    int x = 10;
    int *px = &x;
    std::cout << "px = " << std::hex << px << '\n';
    // px = 0x7ffd7b1861b4 // - example output, may vary

    A a(px);
    a.show();
    // data = 0x7ffd7b1861b4

    px = nullptr;
    std::cout << "px = " << std::hex << px << '\n';
    // px = 0

    a.show();
    // data = 0x7ffd7b1861b4

    px = a.getData();
    px = nullptr;
    a.show();
    // data = 0x7ffd7b1861b4

    // a.getData() = nullptr;
    // error: lvalue required as left operand of assignment

    return 0;
}