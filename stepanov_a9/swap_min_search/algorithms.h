#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "binary_counter.h"

template<typename T, typename Compare>
// requires Compare defines a StrictWeakOrdering on T
inline
void sort_two(T& a, T& b, Compare cmp) {
    if (cmp(b, a)) std::swap(a, b);
}

template<typename T>
inline
void sort_two(T& a, T& b) {
    sort_two(a, b, std::less<T>());
}

template <typename I, typename Compare>
// requires I is a ForwardIterator
// Compare is a StrictWeakOrdering on I::value_type

// I is not an InputIterator because they only go over the data once
//     so you can't store values like done here: "I min_el = first;"
inline
I min_element(I first, I last, Compare cmp) {
    if (first == last) return last;

    I min_el = first;
    ++first;
    while (first != last) {
        if (cmp(*first, *min_el)) {
            min_el = first;
        }
        ++first;
    }
    return min_el;
}

template<typename I>
inline
I successor(I i) {
    return ++i;
}
template <typename I, typename Compare>
// requires I is a ForwardIterator
// Compare is a StrictWeakOrdering on I::value_type
inline
std::pair<I,I> minmax_elements_2(I first, I last, Compare cmp) {
    if (first == last) return std::make_pair(last, last);
    I min_el = first;
    ++first;
    if (first == last) return std::make_pair(min_el, min_el);
    I max_el = first;
    if (cmp(*max_el, *min_el)) {
        std::swap(min_el, max_el);
    }
    I next = successor(first);
    while (first != last && next != last) {
        // min_el points to the current minimum
        // max_el - current maximum
        // 2 more elements are available: first, next
        if (cmp(*next, *first)) {
            std::swap(next, first);
        }
        if (!cmp(*next, *max_el)) {
            max_el = next;
        }
        if (cmp(*first, *min_el)) {
            min_el = first;
        }
        ++++first;
        ++++next;
    }
    if (next != last) { // in case we swapped next and first somewhere
        first = next;
    }
    if (first != last) {
        if (!cmp(*first, *max_el)) {
            max_el = first;
        }
        if (cmp(*first, *min_el)) {
            min_el = first;
        }
    }

    return std::make_pair(min_el, max_el);
}

// their code
template <typename I, typename Compare>
// requires I is a ForwardIterator
// and Compare is a StrictWeakOrdering on ValueType(I)
inline
std::pair<I, I> minmax_elements(I first, I last, Compare cmp) {
    if (first == last) return std::make_pair(last, last);
    I min_el = first;
    ++first;
    if (first == last) return std::make_pair(min_el, min_el);
    ++first;
    I max_el = first;
    if (cmp(*max_el, *min_el)) {
        std::swap(min_el, max_el);
    }
    while (first != last && successor(first) != last) {
        // invariants:
        // min_el points to current minimum
        // max_el points to current maximum
        // first and next point to next 2 elements
        I potential_min = first;
        I potential_max = successor(first);
        if (cmp(*potential_max, *potential_min)) {
            std::swap(potential_max, potential_min);
        }
        if (!cmp(*potential_max, *max_el)) {
            max_el = potential_max;
        }
        if (cmp(*potential_min, *min_el)) {
            min_el = potential_min;
        }
        ++first;
        ++first;
    }
    if (first != last) {
        if (!cmp(*first, *max_el)) {
            max_el = first;
        }
        if (cmp(*first, *min_el)) {
            min_el = first;
        }
    }
    return std::make_pair(min_el, max_el);
}

#endif //ALGORITHMS_H
