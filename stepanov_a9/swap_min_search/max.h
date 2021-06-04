#ifndef MAX_H
#define MAX_H

template<typename T, typename Compare>
// requires Compare defines a StrictWeakOrdering on T
inline
const T& max(const T& a, const T& b, Compare cmp) {
    if (!cmp(a, b)) {
        return b;
    }
    else {
        return a;
    }
}

template<typename T>
inline
const T& max(const T& a, const T& b) {
    return ::max(a, b, std::greater<T>());
}

#endif //MAX_H
