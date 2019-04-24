#include <iostream>
#include <exception>
#include <string>

class MyExcept: public std::exception {
    std::string data;
public:
    explicit MyExcept(const char* i): data(i) {};
    const char* what() const noexcept override { return data.c_str(); }
};

class A {
public:
    A() { std::cout << "A()\n"; }
    ~A() noexcept(false) {
        std::cout << "~A()\n";
        throw MyExcept("100");
    }
};

int main() {
//    {
//        /**
//         * A()
//         * terminate called after throwing an instance of 'MyExcept'
//         * what():  100
//         * ~A()
//         * Process finished with exit code X
//         */
//        try {
//            A a;
//            throw MyExcept("200");
//            /**
//             * The process of calling destructors for automatic objects constructed on the path from a try block
//             * to a throw-expression is called “stack unwinding.”
//             * If a destructor called during stack unwinding exits with an exception, std::terminate is called
//             */
//        }
//        catch (const MyExcept& e) {
//            std::cout << "e = " << e.what() << "\n";
//        }
//    }
    {
        try {
            A a;
        }
        catch (const MyExcept& e) {
            std::cout << "e = " << e.what() << "\n";
        }
    }
    std::cout << "\n";
    return 0;
}