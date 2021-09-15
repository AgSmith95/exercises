#ifndef SHORTEST_SUPERSEQUENCE_SHORTEST_SUPERSEQUENCE_HPP
#define SHORTEST_SUPERSEQUENCE_SHORTEST_SUPERSEQUENCE_HPP

#include <unordered_map>

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

using lookup_key = std::pair<size_t , size_t>;
struct pair_hash {
    std::size_t operator()(const lookup_key& key) const noexcept {
        std::size_t h1 = key.first;
        std::size_t h2 = key.second;
        return h1 ^ (h2 << 1);
    }
};
using lookup_table = std::unordered_map<lookup_key, unsigned long long, pair_hash>;

template<typename It> // It - ForwardIterator
unsigned long long shortest_supersequence(It x_first, It x_last, It y_first, It y_last,
                                          lookup_table &lookup) {
    unsigned long res;
    if (x_first == x_last || y_first == y_last) {
        res = std::distance(y_first, y_last) + std::distance(x_first, x_last);
    }
    else {
        lookup_key key{std::distance(x_first, x_last),
                       std::distance(y_first, y_last)};

        auto found = lookup.find(key);
        if (found == lookup.end()) {
            unsigned long long tmp_res;
            if (*x_first == *y_first) {
                tmp_res = 1 + shortest_supersequence(++x_first, x_last, ++y_first, y_last);
            }
            else {
                unsigned long long left = shortest_supersequence(::next(x_first), x_last,
                                                                 y_first, y_last);
                unsigned long long right = shortest_supersequence(x_first, x_last,
                                                                  ::next(y_first), y_last);
                tmp_res = 1 + ::min(left, right);
            }

            found = lookup.insert({key, tmp_res}).first;
        }

        res = found->second;
    }

    return res;
}

#endif //SHORTEST_SUPERSEQUENCE_SHORTEST_SUPERSEQUENCE_HPP
