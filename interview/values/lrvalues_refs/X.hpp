#ifndef LRVALUES_X_HPP
#define LRVALUES_X_HPP

class X {
public:
    X() { std::cout << "X()\n"; };
    void use() const {};
    // copy constructor / assignment
    X(const X& x) { std::cout << "X copy constructed\n"; };
    X& operator=(const X& x) { std::cout << "X copy assigned\n"; return *this; };
    // move constructor / assignment
    X(X&& x) noexcept { std::cout << "X move constructed\n"; };
    X& operator=(X&& x) noexcept { std::cout << "X move assigned\n"; return *this; };
};

#endif //LRVALUES_X_HPP
