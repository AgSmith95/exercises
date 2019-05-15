#include <iostream>

// Method 1: templates
template <unsigned long long N>
struct fib;

template <>
struct fib<0>
{
    static const unsigned long long value = 0;
};
template <>
struct fib<1>
{
    static const unsigned long long value = 1;
};

template <unsigned long long N>
struct fib
{
    static const unsigned long long value = fib<N-1>::value + fib<N-2>::value;
};

// Method 2: constexpr
constexpr unsigned long long fibo(unsigned long long n) {
    return (n <= 1) ? 1 :
        fibo(n-1) + fibo(n-2);
}
constexpr unsigned long long fibo_ = fibo(26);  // compile time
                                                // only 26 due to stupid microsoft compiler

int main() {
    std::cout << "fib<0> = " << fib<0>::value << "\n";
    std::cout << "fib<0> = " << fib<1>::value << "\n";
    std::cout << "fib<45> = " << fib<45>::value << "\n";
    std::cout << "fibo_ = " << fibo_ << "\n";
    std::cout << "fibo(10) = " << fibo(10) << "\n"; // run time
    return 0;
}