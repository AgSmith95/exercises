#include <iostream>
#include <algorithm>
#include <vector>

#include "shortest_supersequence.hpp"

/**
 * Find Shortest Common Supersequence length
 *      For sequences X and Y find such supersequence Z
 *      so that both X and Y are subsequences of Z
 *
 * Example:
 *      X: ABCBDAB
 *      Y: BDCABA
 *      returns 9
 *
 *      because shortest supersequences are:
 *          ABC BDC ABA
 *          ABD CAB DAB
 *          ABD CBD ABA
 */

int main() {
    std::vector<char> X = {'A','B','C','B','D','A','B'};
    std::vector<char> Y =     {'B','D','C','A','B','A'};
    std::cout << shortest_supersequence(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 9
    std::cout << shortest_supersequence(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 9

    lookup_table lookup;
    std::cout << shortest_supersequence(X.begin(), X.end(), Y.begin(), Y.end(), lookup) << "\n"; // 9
    lookup.clear();
    std::cout << shortest_supersequence(Y.begin(), Y.end(), X.begin(), X.end(), lookup) << "\n"; // 9
    return 0;
}