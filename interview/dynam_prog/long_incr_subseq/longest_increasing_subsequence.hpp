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
void print_container(It first, It last, bool end_line = true) {
    std::cout << '[' << ' ';
    for (; first != last; ++first) {
        std::cout << *first << ' ';
    }
    std::cout << ']';
    if (end_line) std::cout << '\n';
}
