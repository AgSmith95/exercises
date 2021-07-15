#ifndef SINGLETON_H
#define SINGLETON_H

template<typename T>
struct singleton {
    typedef T value_type;
    T value;
    // type conversions from and to T
    explicit singleton(const T& x): value(x) {}
    explicit operator T() const { return value; }
    // template<typename U>
    // singleton(const singleton<U>& x): value(x.value) {}; // if possible - do not use this

    // semi-regular
    singleton(const singleton& other): value(other.value) {}
    singleton() {}
    ~singleton() {}
    singleton& operator=(const singleton& other) {
        value = other.value;
        return *this;
    }

    // regular
    friend
    bool operator==(const singleton& x, const singleton& y) {
        return x.value == y.value;
    }
    friend
    bool operator!=(const singleton& x, const singleton& y) {
        return !(x == y);
    }

    // totally-ordered
    friend
    bool operator<(const singleton& x, const singleton& y) {
        return x.value < y.value;
    }
    friend
    bool operator>(const singleton& x, const singleton& y) {
        return y < x;
    }
    friend
    bool operator<=(const singleton& x, const singleton& y) {
        return !(y < x);
    }
    friend
    bool operator>=(const singleton& x, const singleton& y) {
        return !(x < y);
    }
};

#endif //SINGLETON_H
