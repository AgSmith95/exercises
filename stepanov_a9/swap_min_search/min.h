#ifndef MIN_H
#define MIN_H

#include <functional>

template<typename T, typename Compare>
// requires Compare defines a StrictWeakOrdering on T
inline
const T& min(const T& a, const T& b, Compare cmp) {
    if (cmp(b, a)) {
        return b;
    }
    else {
        return a;
    }
}

template <typename T>
inline
const T& min(const T& a, const T& b) {
    return ::min(a, b, std::less<T>{});
}

#endif //MIN_H
