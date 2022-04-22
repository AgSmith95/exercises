#ifndef edit_distance_EDIT_DISTANCE_HPP
#define edit_distance_EDIT_DISTANCE_HPP

#include <algorithm>
#include <vector>

template<typename It>
using vt = typename std::iterator_traits<It>::value_type;

template <typename It>
It search(It first, It last, const vt<It> &value, size_t &count) {
    for (; first != last && *first != value; ++first) {
        ++count;
    }
    return first;
}

template<typename It> // It - ForwardIterator
size_t edit_distance_recursive(It x_first, It x_last, It y_first, It y_last) {
    if (x_first == x_last) return std::distance(y_first, y_last);
    else if (y_first == y_last) return std::distance(x_first, x_last);
    else if (*x_first == *y_first) return edit_distance_recursive(std::next(x_first), x_last, std::next(y_first), y_last);
    else {
        size_t tail_x = edit_distance_recursive(std::next(x_first), x_last, y_first, y_last);
        size_t tail_y = edit_distance_recursive(x_first, x_last, std::next(y_first), y_last);
        size_t tail = edit_distance_recursive(std::next(x_first), x_last, std::next(y_first), y_last);

        return 1 + std::min(std::min(tail_x, tail_y), tail);
    }
}

template<typename It> // It - ForwardIterator
size_t edit_distance_matrix(It x_first, It x_last, It y_first, It y_last) {
    size_t n = std::distance(x_first, x_last);
    size_t m = std::distance(y_first, y_last);

    if (n == 0) return m;
    if (m == 0) return n;

    std::vector<std::vector<size_t>> d(n, std::vector<size_t>(m, 0));

    for (size_t i = 1; i < n; ++i) d[i][0] = i;
    for (size_t j = 1; j < m; ++j) d[0][j] = j;

    for (size_t j = 1; j < m; ++j) {
        for (size_t i = 1; i < n; ++i) {
            size_t deletion     = d[i-1][j] + 1;
            size_t insertion    = d[i][j-1] + 1;
            size_t substitution = d[i-1][j-1] + static_cast<size_t>(*std::next(x_first, i) != *std::next(y_first, j));

            d[i][j] = std::min(std::min(deletion, insertion), substitution);
        }
    }

    return d[n-1][m-1];
}

#endif //edit_distance_EDIT_DISTANCE_HPP
