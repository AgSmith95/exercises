#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H

#include <cstddef>

struct instrumented_base {
    enum operations {
        n, copy, assignment, destructor, default_constructor, equality, comparison, construction
    };
    static const size_t number_ops = 8;
    static double counts[number_ops];
    static const char* counter_names[number_ops];
    static void initialize(size_t);
};

template<typename T>
struct instrumented: instrumented_base {
    typedef T value_type;
    T value;
    // type conversions from and to T
    explicit instrumented(const T& x): value(x) { ++counts[construction]; }
    // explicit operator T() const { return value; }
    // template<typename U>
    // instrumented(const instrumented<U>& x): value(x.value) {}; // if possible - do not use this

    // semi-regular
    instrumented(const instrumented& other): value(other.value) { ++counts[copy]; }
    instrumented() { ++counts[default_constructor]; }
    ~instrumented() { ++counts[destructor]; }
    instrumented& operator=(const instrumented& other) {
        ++counts[assignment];
        value = other.value;
        return *this;
    }

    // regular
    friend
    bool operator==(const instrumented& x, const instrumented& y) {
        ++counts[equality];
        return x.value == y.value;
    }
    friend
    bool operator!=(const instrumented& x, const instrumented& y) {
        return !(x == y);
    }

    // totally-ordered
    friend
    bool operator<(const instrumented& x, const instrumented& y) {
        ++counts[comparison];
        return x.value < y.value;
    }
    friend
    bool operator>(const instrumented& x, const instrumented& y) {
        return y < x;
    }
    friend
    bool operator<=(const instrumented& x, const instrumented& y) {
        return !(y < x);
    }
    friend
    bool operator>=(const instrumented& x, const instrumented& y) {
        return !(x < y);
    }
};

#endif // INSTRUMENTED_H
