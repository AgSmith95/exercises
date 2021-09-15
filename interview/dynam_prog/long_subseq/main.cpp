#include <iostream>
#include <vector>

/**
 * Find Longest Common Subsequence length
 *      (Note: subsequence is not a substring)
 *
 * Example:
 *      X: ABCBDAB
 *      Y: BDCABA
 *      returns 4
 *
 *      because longest subsequences are:
 *          BDAB, BCAB, BCBA
 */

template<typename T>
T max(const T& x, const T& y) {
    return y < x ? x : y;
}

template<typename It> // It - ForwardIterator
It next(It it) {
    return ++it;
}

template<typename It> // It - ForwardIterator
unsigned long long longest_subsequence(It x_first, It x_last, It y_first, It y_last) {
    unsigned long res;
    if (x_first == x_last || y_first == y_last) res = 0;
    else if (*x_first == *y_first) {
        res = 1 + longest_subsequence(++x_first, x_last, ++y_first, y_last);
    }
    else {
        unsigned long long left = longest_subsequence(::next(x_first), x_last, y_first, y_last);
        unsigned long long right = longest_subsequence(x_first, x_last, ::next(y_first), y_last);
        res = ::max(left, right);
    }

    return res;
}

int main() {
    std::vector<char> X = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    std::vector<char> Y = {'B','D','C','A','B','A'};
    std::cout << longest_subsequence(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 4
    std::cout << longest_subsequence(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 4
    return 0;
}