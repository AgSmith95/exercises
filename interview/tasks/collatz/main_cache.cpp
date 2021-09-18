#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>

static const unsigned long long CACHE_SIZE = 1048576; // 2^20

using lookup_table = std::vector<unsigned long long>;

unsigned long long collatz(unsigned long long N, lookup_table &lookup) {
    unsigned long long result = 0;
    unsigned long long n = N;
    size_t cache_size = lookup.size();
    while (n != 1) {
        if (n < cache_size && lookup[n] != 0) {
            result += lookup[n];
            break;
        }
        else {
            ++result;
            if (n & 1) {
                n = (3 * n + 1) >> 1;
                ++result;
            }
            else {
                n >>= 1;
            }
        }
    }
    lookup[N] = result;

    return result;
}

unsigned long long longest_collatz_uptoN(unsigned long long n, lookup_table &lookup) {
    unsigned long long index = 0;
    unsigned long long max = 0;
    unsigned long long current;
    for (; n > 1; --n) {
        if (lookup[n] != 0) {
            current = lookup[n];
        }
        else {
            current = collatz(n, lookup);
        }

        if (current > max) {
            max = current;
            index = n;
        }
    }

    return index;
}

int main(int, char **argv) {
    int n = atoi(argv[1]);
    lookup_table lookup(n, 0);
    lookup[0] = 0; lookup[1] = 1; lookup[2] = 2; lookup[4] = 3;
    std::cout << longest_collatz_uptoN(n, lookup) << '\n';
    return 0;
}