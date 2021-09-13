#include <iostream>
#include <cstdlib>

unsigned long long collatz(unsigned long long n) {
    //if (n == 0) return 0; // it is an error but ok
    if (n == 1) return 1;
    else if (n == 2) return 2;

    unsigned long long result = 0;
    while (n != 4) {
        ++result;
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = 3*n + 1;
        }
    }
    result += 3;

    return result;
}

unsigned long long longest_collatz_uptoN(unsigned long long n) {
    if (n == 0) return 0;

    unsigned long long index = 1;
    unsigned long long max = 1;
    unsigned long long current;
    while (n > 1) {
        current = collatz(n);
        if (current > max) {
            max = current;
            index = n;
        }
        --n;
    }

    return index;
}

int main(int, char **argv) {
    int n = atoi(argv[1]);
    std::cout << longest_collatz_uptoN(n) << '\n';
    return 0;
}