#pragma once

#include <vector>
#include <iterator>
#include <limits>
#include <algorithm>
#include <iostream>

template<typename It>
using vt = typename std::iterator_traits<It>::value_type;

template<typename It>
std::vector<vt<It>> longest_increasing_subsequence(It first, It last, vt<It> prev = std::numeric_limits<vt<It>>::min()) {
    if (first == last) return {};
    else if (prev < *first) {
        vt<It> current = *first;
        std::vector<vt<It>> included = std::move(longest_increasing_subsequence(std::next(first), last, current));
        std::vector<vt<It>> excluded = std::move(longest_increasing_subsequence(std::next(first), last, prev));
        if (1 + included.size() > excluded.size()) {
            included.insert(included.begin(), *first);
            return included;
        }
        else {
            return excluded;
        }
    }
    else {
        return longest_increasing_subsequence(std::next(first), last, prev);
    }
}

template<typename It>
unsigned long long longest_increasing_subsequence_num(It first, It last) {
    if (first != last) {
        std::vector<unsigned long long> L(std::distance(first, last));
        auto L_begin = L.begin();
        *L_begin = 1;

        auto LI = std::next(L_begin);
        for (It I = std::next(first); I != last; ++I, ++LI) {
            auto LJ = L_begin;
            for (It J = first; J != I; ++J, ++LJ) {
                if (*J < *I && *LJ > *LI) {
                    *LI = *LJ;
                }
            }
            ++*LI;
        }

        auto max = std::max_element(L_begin, L.end());
        return *max;
    }
    return 0;
}

template<typename It>
using tmp_storage_iterator = typename std::vector< std::vector<vt<It>> >::iterator;

template<typename It>
std::vector<vt<It>> longest_increasing_subsequence_dynamic(It first, It last) {
    if (first != last) {
        std::vector< std::vector<vt<It>> > L(std::distance(first, last), std::vector<vt<It>>{});
        tmp_storage_iterator<It> L_begin = L.begin();
        L_begin->push_back(*first);

        tmp_storage_iterator<It> LI = std::next(L_begin);
        for (It I = std::next(first); I != last; ++I, ++LI) {
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
        return *max;
    }
    return {};
}

template<typename It>
unsigned long long lis_nlogn_num(It first, It last) {
    if (first != last) {
        std::vector<vt<It>> s;
        for (It I = first; I != last; ++I) {
            auto place = std::lower_bound(s.begin(), s.end(), *I);
            if (place == s.end()) {
                s.push_back(*I);
            }
            else {
                *place = *I;
            }
        }

        return s.size();
    }
    return 0;
}

template<typename It>
std::vector<vt<It>> lis_nlogn(It first, It last) {
    std::vector<vt<It>> result{};
    if (first != last) {
        std::vector<vt<It>> s;
        for (It I = first; I != last; ++I) {
            auto place = std::lower_bound(s.begin(), s.end(), *I);
            if (place == s.end()) {
                s.push_back(*I);
                result.push_back(*I);
            }
            else {
                *place = *I;
            }
        }
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
