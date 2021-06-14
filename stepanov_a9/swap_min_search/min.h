#ifndef MIN_H
#define MIN_H

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
    return ::min(a, b, std::less<T>());
}

template <typename I, typename Compare>
// requires I is a ForwardIterator
// I is not an InputIterator because they only go over the data once
//     so you can't store values like done here: "I min_el = first;"
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

#endif //MIN_H
