// usage: collatz_cached N
//		N - number up to which you need to check

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>

using lookup_table = std::vector<uint64_t>;

uint64_t collatz(uint64_t N, lookup_table &lookup) {
    uint64_t result = 0;
    uint64_t n = N;
    size_t cache_size = lookup.size();
    while (n != 1) {
        uint64_t search = n < cache_size ? lookup[n] : 0;
        if (search != 0) {
            result += search;
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

uint64_t longest_collatz_uptoN(uint64_t n, lookup_table &lookup) {
    uint64_t index = 0;
    uint64_t max = 0;
    uint64_t current;
    uint64_t stop = n;
    for (n = 1; n < stop; ++n) {
        uint64_t search = lookup[n];
        if (search != 0) {
            current = search;
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