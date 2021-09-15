#include <iostream>
#include <algorithm>
#include <vector>

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

template<typename T>
T min(const T& x, const T& y) {
    return y < x ? y : x;
}

template<typename It> // It - ForwardIterator
It next(It it) {
    return ++it;
}

template<typename It> // It - ForwardIterator
unsigned long long shortest_supersequence(It x_first, It x_last, It y_first, It y_last) {
    unsigned long res;
    if (x_first == x_last || y_first == y_last) {
        res = std::distance(y_first, y_last) + std::distance(x_first, x_last);
    }
    else if (*x_first == *y_first) {
        res = 1 + shortest_supersequence(++x_first, x_last, ++y_first, y_last);
    }
    else {
        unsigned long long left = shortest_supersequence(::next(x_first), x_last, y_first, y_last);
        unsigned long long right = shortest_supersequence(x_first, x_last, ::next(y_first), y_last);
        res = 1 + ::min(left, right);
    }

    return res;
}

int main() {
    std::vector<char> X = {'A','B','C','B','D','A','B'};
    std::vector<char> Y =     {'B','D','C','A','B','A'};
    std::cout << shortest_supersequence(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 9
    std::cout << shortest_supersequence(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 9
    return 0;
}