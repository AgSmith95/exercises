// usage: collatz N
//		N - number up to which you need to check

#include <iostream>
#include <cstdlib>

unsigned long long collatz(unsigned long long n) {
    unsigned long long result = 0;
    while (n != 2) {
        ++result;
        if (n & 1) {
            n = (3*n + 1) >> 1;
            ++result;
        }
        else {
            n >>= 1;
        }
    }
    result += 2;

    return result;
}

unsigned long long longest_collatz_uptoN(unsigned long long n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;

    unsigned long long index = 2;
    unsigned long long max = 2;
    unsigned long long current;
    for (; n > 1; --n) {
        current = collatz(n);
        if (current > max) {
            max = current;
            index = n;
        }
    }

    return index;
}

int main(int, char **argv) {
    int n = atoi(argv[1]);
    std::cout << longest_collatz_uptoN(n) << '\n';
    return 0;
}