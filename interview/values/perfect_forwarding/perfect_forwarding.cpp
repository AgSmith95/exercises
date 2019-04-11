#include <iostream>
#include <utility>

class X {
public:
    X() {
        std::cout << "X()\n";
    }
    X(const X& x) {
        std::cout << "X(const X& x)\n";
    }
    X(X&& x) noexcept {
        std::cout << "X(X&& x)\n";
    }

    X& operator=(X const& other) {  // copy-assignment
        std::cout << "operator=(X const& other)\n";
        return *this;
    }
    X& operator=(X && other) noexcept {  //  move-assignment
        std::cout << "operator=(X&& other)\n";
        return *this;
    }
};

void g(const X& x) {
    std::cout << "g(const X& x)\n";
}
void g(X&& x) {
    std::cout << "g(X&& x)\n";
}

template<typename T>
void no_perf_forw(T&& t) {
    std::cout << "no_pf(T&& t)\n";
    g(t);
}

template<typename T>
void perf_forw(T&& t) {
    std::cout << "no_pf(T&& t)\n";
    g(std::forward<T>(t)); // "std::forward<T>(t)" is equivalent to "static_cast<T&&>(t)"
}

int main() {
    {   // Without perfect forwarding
        X x;

        no_perf_forw(x);
        no_perf_forw(X());
    }
    std::cout << '\n';
    {   // With perfect forwarding
        X x;

        perf_forw(x);
        perf_forw(X());
    }
    return 0;
}