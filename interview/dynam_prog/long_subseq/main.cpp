#include <iostream>
#include <vector>

#include "longest_subsequence.hpp"

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

int main() {
    std::vector<char> X = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    std::vector<char> Y = {'B','D','C','A','B','A'};

    std::cout << longest_subsequence(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 4
    std::cout << longest_subsequence(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 4

    lookup_table lookup;
    std::cout << longest_subsequence(X.begin(), X.end(), Y.begin(), Y.end(), lookup) << "\n"; // 4
    lookup.clear();
    std::cout << longest_subsequence(Y.begin(), Y.end(), X.begin(), X.end(), lookup) << "\n"; // 4
    return 0;
}