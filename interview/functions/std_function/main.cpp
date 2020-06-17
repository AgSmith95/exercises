#include <iostream>
#include <functional>

class A {
    int data;
public:
    A(int i): data{i} {}
    void print_A(int i) const {
        std::cout << "I am A : " << i << ", my data - " << data << '\n';
    }
    int getData() const {
        return data;
    }
};

int foo(int i) {
    std::cout << "foo( " << i << " ) = " << i+10 << '\n';
    return i + 10;
}

int main() {
    std::function<int(int)> foo_f_1 = foo;
    foo_f_1(100);

    std::function<void(double)> lambda_1 = [](double d){
        std::cout << "I am lambda with double param : " << d << '\n';
    };
    lambda_1(20.3);

    A a(10);
    std::function<void(const A&, int)> print_A_f_1 = &A::print_A;
    print_A_f_1(a, 33);

    std::function lambda_2 = [&](int i) {
        std::cout << "lambda with capture list : " << i + a.getData() << '\n';
    };
    lambda_2(777);

    return 0;
}