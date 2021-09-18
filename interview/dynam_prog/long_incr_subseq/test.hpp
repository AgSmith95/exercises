#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <cassert>

#include "longest_increasing_subsequence.hpp"

void test_nlogn() {
#ifdef DEBUG
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<size_t> dist_len {0, 1000};
    std::uniform_int_distribution<int> dist_val {-1000, 1000};
    auto gen_len = [&dist_len, &g]() { return dist_len(g); };
    auto gen_num = [&dist_val, &g]() { return dist_val(g); };

    std::cout << "\nINITIATING TEST SEQUENCE\n\n";

    std::vector<int> vi;
    vi.reserve(1000);
    for (size_t i = 0; i < 1024*16; ++i) {
        if (i % 64 == 0) std::cout << i << "\n";
        std::cout << '.';

        size_t len = gen_len(); // generate new length
        // fill the vector with random numbers
        for(size_t j = 0; j < len; ++j) {
            vi[j] = gen_num();
        }
        // find sequence using nlogn method
        std::vector<int> result = lis_nlogn(vi.begin(), vi.begin() + len);
        // compare length of the sequence with the length found using dynamic programming method
        assert(result.size() == longest_increasing_subsequence_num(vi.begin(), vi.begin() + len));
        // check if sequence is sorted
        assert(std::is_sorted(result.begin(), result.end()));
    }

    std::cout << "\nTESTING COMPLETE SUCCESSFULLY!\n\n";
#endif
}
