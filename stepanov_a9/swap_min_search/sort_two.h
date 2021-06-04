#ifndef SORT_TWO_H
#define SORT_TWO_H

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

#endif //SORT_TWO_H
