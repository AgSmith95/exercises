#pragma once

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <cassert>

#include "longest_increasing_subsequence.hpp"

template<typename It>
It shift_until_not_equal(It first, It last, vt<It> value) {
    while (first != last && *first != value) ++first;
    return first;
}

template<typename It>
bool is_subsequence(It sub_first, It sub_last, It seq_first, It seq_last) {
    if (sub_first == sub_last) return true;
    if (seq_first == seq_last) return false;

    while (seq_first != seq_last && sub_first != sub_last) {
        if (*seq_first != *sub_first) seq_first = shift_until_not_equal(seq_first, seq_last, *sub_first);
        ++sub_first;
    }

    return sub_first == sub_last;
}

void test_nlogn() {
#ifdef DEBUG
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<size_t> dist_len {0, 1000};
    std::uniform_int_distribution<int> dist_val {-1000, 1000};
    auto gen_len = [&dist_len, &g]() { return dist_len(g); };
    auto gen_num = [&dist_val, &g]() { return dist_val(g); };

    std::cout << "\nINITIATING TEST SEQUENCE\n\n";

    int error_code = 0;

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
        // compare length of the sequence with the length found using nlogn method
        if (result.size() != lis_nlogn_num(vi.begin(), vi.begin() + len)) {
            std::cout << "\n!!!  SIZES DON'T MATCH  !!!\n";
            error_code = 1;
        }
        // check if sequence is sorted
        if (!std::is_sorted(result.begin(), result.end())) {
            std::cout << "\n!!!  IS NOT SORTED  !!!\n";
            error_code = 2;
        }
        // check if the result is a subsequence of the input
        if (!is_subsequence(result.begin(), result.end(), vi.begin(), vi.begin() + len)) {
            std::cout << "\n!!!  IS NOT PROPER SUBSEQUENCE  !!!\n";
            error_code = 3;
        }

        if (error_code != 0) {
            std::cout << "INPUT :";
            print_container(vi.begin(), vi.begin() + len);
            std::cout << "RESULT:";
            print_container(result.begin(), result.end());
            break;
        }
    }

    if (!error_code) std::cout << "\nTESTING COMPLETE SUCCESSFULLY!\n\n";
#endif
}
