#ifndef BINARY_COUNTER_H
#define BINARY_COUNTER_H

#include <vector>

template<typename T, typename I, typename Op>
// requires Op is BinaryOperation(T)
// requires Op is associative
// requires I is ForwardIterator and ValueType(I) == T
T add_to_counter(I first, I last, Op op, const T& zero, T carry) {
    while (first != last) {
        if (*first  == zero) {
            *first = carry;
            return zero;
        }
        carry = op(*first, carry);
        *first = zero;
        ++first;
    }
    return carry;
}

template<typename T, typename I, typename Op>
// requires Op is BinaryOperation(T)
// requires Op is associative
// requires I is ForwardIterator and ValueType(I) == T
T reduce_counter(I first, I last, Op op, const T& zero) {
    while (first != last && *first == zero) {
        ++first;
    }
    if (first == last) return zero;

    T result = *first;
    ++first;
    while (first != last) {
        if (*first != zero) {
            result = op(*first, result);
        }
        ++first;
    }
    return result;
}

// Class implementation. State:
// - vector for the counter
// - zero
// - op
template<typename T, typename Op>
class binary_counter {
private:
    std::vector<T> counter;
    T zero;
    Op op;
public:
    // Constructor. Input arguments:
    binary_counter(const Op& op, const T& zero): zero(zero), op(op) {
        counter.reserve(32);
    }

    // add
    // returns: nothing
    void add(T x) {
        x = add_to_counter(counter.begin(), counter.end(), op, zero, x);
        if (x != zero) counter.push_back(x);
    }

    // reduce
    // returns: value of the counter
    T reduce() {
        return reduce_counter(counter.begin(), counter.end(), op, zero);
    }
};

template<typename Compare>
// requires
class min_op {
private:
    Compare cmp;
public:
    explicit min_op(const Compare& cmp): cmp(cmp) {}

    // What's the iterator type? We can templatize here.
    // Functorize!
    template<typename I>
    I operator()(const I& x, const I& y) {
        return cmp(*y, *x) ? y : x;
//        if (cmp(*y, *x)) {
//            return y;
//        }
//        else {
//            return x;
//        }
    }
};



#endif//BINARY_COUNTER_H
