#ifndef edit_distance_EDIT_DISTANCE_HPP
#define edit_distance_EDIT_DISTANCE_HPP

#include <algorithm>

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

#endif //edit_distance_EDIT_DISTANCE_HPP
