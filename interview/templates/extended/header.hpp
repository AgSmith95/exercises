#ifndef HEADER_HPP
#define HEADER_HPP

// Required at least C++14
template <typename T, typename U>
auto add(T const& a, U const& b) /* -> decltype() */ {
    return a + b;
}
// C++11 signature would be:
//auto add(T const& a, U const& b) -> decltype(a + b) {

// Type traits
// 1. is integer?
template <class T>
struct is_int {
    static bool const value{false};
};

template <>
struct is_int<int> {
    static bool const value{true};
};

// C++17 required for this
template <class T>
constexpr bool is_int_v{ is_int<T>::value };

// 2. are 2 types the same?
template <class T, class U>
struct is_same {
    static bool const value{false};
};

template <class T>
struct is_same<T, T> {
    static bool const value{true};
};

// C++17 required
template <class T, class U>
constexpr bool is_same_v{ is_same<T, U>::value };

#endif
