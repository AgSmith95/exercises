#include <iostream>
#include <memory>

struct A {
    int x = 0x41424344;
    ~A() {
        std::cout << "~A";
    }
};

struct A_deleter {
    explicit A_deleter(size_t n) : size(n) {}
    void operator()(A* a) const {
        std::destroy_n(a, size);
    }
    size_t size;
};

int main() {
    char buff[129] = {};
    std::unique_ptr<A[], A_deleter> upa{ new (buff) A[32], A_deleter{32} };
    upa.get()[6].x = 0x59595959;
    std::cout << buff << std::endl;
    return 0;
}
