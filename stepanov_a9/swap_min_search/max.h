#ifndef MAX_H
#define MAX_H

template<typename T, typename Compare>
// requires Compare defines a StrictWeakOrdering on T
inline
const T& max(const T& a, const T& b, Compare cmp) {
    if (cmp(a, b)) {// if (a > b)
        return a;
    }
    else {          // if (a <= b)
        return b;   // return b in case of equality, because bigger should be to the right
    }
}

template<typename T>
inline
const T& max(const T& a, const T& b) {
    return ::max(a, b, std::greater<T>());
}

#endif //MAX_H
