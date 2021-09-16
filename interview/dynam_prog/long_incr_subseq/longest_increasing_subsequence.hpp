#pragma once

#include <vector>
#include <iterator>
#include <limits>
#include <algorithm>
#include <iostream>

template<typename It>
using vt = typename std::iterator_traits<It>::value_type;

template<typename It> // It - ForwardIterator
It next(It it) {
    return ++it;
}

template<typename It>
std::vector<vt<It>> longest_increasing_subsequence(It first, It last, vt<It> prev = std::numeric_limits<vt<It>>::min()) {
    std::vector<vt<It>> result;
    if (first == last) return result;
    else if (prev < *first) {
        vt<It> current = *first;
        std::vector<vt<It>> included = std::move(longest_increasing_subsequence(::next(first), last, current));
        std::vector<vt<It>> excluded = std::move(longest_increasing_subsequence(::next(first), last, prev));
        if (1 + included.size() > excluded.size()) {
            result.push_back(current);
            std::move(included.begin(), included.end(), std::back_inserter(result));
        }
        else {
            result = std::move(excluded);
        }
    }
    else {
        result = std::move(longest_increasing_subsequence(::next(first), last, prev));
    }
    return result;
}

template<typename It>
unsigned long long longest_increasing_subsequence_num(It first, It last) {
    unsigned long long result;
    if (first == last) result = 0;
    else {
        std::vector<unsigned long long> L(std::distance(first, last));
        auto L_begin = L.begin();
        *L_begin = 1;

        auto LI = ::next(L_begin);
        for (It I = ::next(first); I != last; ++I, ++LI) {
            auto LJ = L_begin;
            for (It J = first; J != I; ++J, ++LJ) {
                if (*J < *I && *LJ > *LI) {
                    *LI = *LJ;
                }
            }
            ++*LI;
        }

        auto max = std::max_element(L_begin, L.end());
        result = *max;
    }
    return result;
}

template<typename It>
using tmp_storage_iterator = typename std::vector< std::vector<vt<It>> >::iterator;

template<typename It>
std::vector<vt<It>> longest_increasing_subsequence_dynamic(It first, It last) {
    std::vector<vt<It>> result{};
    if (first != last) {
        std::vector< std::vector<vt<It>> > L(std::distance(first, last), std::vector<vt<It>>{});
        tmp_storage_iterator<It> L_begin = L.begin();
        L_begin->push_back(*first);

        tmp_storage_iterator<It> LI = ::next(L_begin);
        for (It I = ::next(first); I != last; ++I, ++LI) {
            auto LJ = L_begin;
            for (It J = first; J != I; ++J, ++LJ) {
                if (*J < *I && LJ->size() > LI->size()) {
                    *LI = *LJ;
                }
            }
            LI->push_back(*I);
        }

        tmp_storage_iterator<It> max = std::max_element(
                L_begin, L.end(),
                [](const std::vector<vt<It>> &x, const std::vector<vt<It>> &y){
                    return y.size() > x.size();
                });
        result = *max;
    }
    return result;
}

template<typename It>
void print_container(It first, It last, bool end_line = true) {
    std::cout << '[' << ' ';
    for (; first != last; ++first) {
        std::cout << *first << ' ';
    }
    std::cout << ']';
    if (end_line) std::cout << '\n';
}
