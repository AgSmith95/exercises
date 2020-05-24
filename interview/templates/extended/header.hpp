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

// 3. Type Functions
template <class T>
struct remove_const {
    using type = T;
};

template <class T>
struct remove_const<T const> {
    using type = T;
};

template <class T>
using remove_const_t = typename remove_const<T>::type;

// 4. Compile-time Conditionals
// 4.1. Tag Dispatch
#include <iterator>
template <class Iterator>
auto distance(Iterator first, Iterator last, std::input_iterator_tag) {
    typename std::iterator_traits<Iterator>::difference_type result{0};
    while (first != last) ++first, ++result;
    return result;
}

template <class RAIter>
auto distance(RAIter first, RAIter last, std::random_access_iterator_tag) {
    return last - first;
}

template <class Iterator>
auto distance(Iterator first, Iterator last) {
    return distance(first, last,
            typename std::iterator_traits<Iterator>::iterator_category{});
    // dispatched at compile time
    // no runtime cost
}

// 4.2. Compile-time Conditionals Overloading
#include <algorithm>
#include <type_traits>

// if we can't memcpy
template<class T, std::size_t N>
std::enable_if_t<not std::is_trivially_copyable_v<T>>
copy_array(T const (& source)[N], T (& dest)[N]) {
    std::copy(source, std::end(source), dest);
}

// if we can memcpy
#include <cstring>
template<class T, std::size_t N>
std::enable_if_t<std::is_trivially_copyable_v<T>>
copy_array(T const (& source)[N], T (& dest)[N]) {
    std::memcpy(dest, source, N * sizeof(T));
}
// declaration can also be like this:
template<class T, std::size_t N>
void copy_array_2(T const (& source)[N], T (& dest)[N],
                  std::enable_if_t<std::is_trivially_copyable_v<T>, int> = 0)
{
    std::memcpy(dest, source, N * sizeof(T));
}

// enable_if_t takes 2 parameters:
//   1. Boolean compile-time constant expression
//   2. The type that is used if the expression is true
//      void by default

// If a template function contains an std::enable_if
// expression then the function is considered for
// overloading only if the condition evaluates to true

// If a condition evaluates to false, the function is
// "disabled" by SFINAE that is, it is removed from the
// overload set and thus from consideration when
// copy_array is called.

// A better name for std::enable_if would be "ignore_unless"
// because the definition is ignored unless the condition if true

// 4.2.1. enable_if implementation
// primary template
template <bool B, class T = void>
struct ignore_unless;

// partial specialization
template <class T>
struct ignore_unless<true, T> {
    using type = T;
};

// How to implement the false case?
// You simply don't, because we don't even want this
// to work in case the condition is false, and let the
// SFINAE to do its work.

// 4.3. Constexpr Conditional
// As of C++17 we can use what the standard calls
// "constexpr if", but it is spelled "if constexpr"
template<class T, std::size_t N>
void copy_array_3(T const (& source)[N], T (& dest)[N]) {
    if constexpr (std::is_trivially_copyable_v<T>) {
        std::memcpy(dest, source, N * sizeof(T));
    }
    else {
        std::copy(source, std::end(source), dest);
    }
}

// 5. Policy classes
// something like this:
template <class T, class CheckingPolicy>
struct MyContainer: private CheckingPolicy {
    // code
};

// to compile, the checking policy class must have
// a member function, which looks like this:
template <class U>
void CheckBounds(U const& lower, U const& upper, U const& index);

// the library can provide some classes that implement
// the obvious policies, but the library user can
// create custom policies as well
template <class U>
void CheckBounds0(U const& lower, U const& upper, U const& index) noexcept {}

#include <cassert>
template <class U>
void CheckBounds1(U const& lower, U const& upper, U const& index) {
    assert( (!(index < lower) && (index < upper)) );
}

template <class U>
void CheckBounds2(U const& lower, U const& upper, U const& index) {
    if ( (index < lower) or !(index < upper) ) {
        throw std::range_error("range error here");
    }
}

// 6. Perfect Forwarding
class APITimer {/*... code, probably ...*/};

template <class APIFunction>
decltype(auto) TimeCall0(APIFunction f) {
//auto TimeCall(APIFunction f) -> decltype(f()) {
    APITimer timer;
    return f();
}

// What if function has a parameter?
/*****
template <class APIFunction, class T>
decltype(auto) TimeCall(APIFunction f, T t) {
// but maybe we need:
//decltype(auto) TimeCall(APIFunction f, T& t) {
// or
//decltype(auto) TimeCall(APIFunction f, T const& t) {
// or
// ...
    APITimer timer;
    return f(t);
}
*****/
// The solution is: forwarding reference
template <class APIFunction, class T>
decltype(auto) TimeCall1(APIFunction f, T&& t) {
    APITimer timer;
    return f(std::forward<T>(t));
}

// What if function has more than 1 parameter?
// - variadic template parameters
template <class APIFunction, class... Args>
decltype(auto) TimeCallMany(APIFunction f, Args&&... args) {
    APITimer timer;
    return f(std::forward<Args>(args)...);
}

// 7. Viewing Deduced Types ~49:00

// 7.1. Standard
/**
    #include <typeinfo>
    typeid(x).name()
 // Assuming:
 //   1. You can build
 //   2. Don't care about const/volatile/reference-ness
 //   3. You can understand what "PK6Widget" means
**/

// 7.2. Boost
/**
    #include "boost/type_index.hpp"
    using boost::typeindex::type_id_with_cvr;
    type_id_with_cvr<T>.pretty_name();
    type_id_with_cvr<decltype(param)>.pretty_name();
 // Can return const/volatile/reference-ness
 // pretty_name demangles name
**/

// Both 7.1. and 7.2. require you to compile and run the program

// 7.3. Compiler
template <class T>
class that_type;

template <class T>
void name_that_type(T& param) {
    that_type<T> tType;
    that_type<decltype(param)> paramType;
}
// if you call name_that_type(x)
// compiler will generate errors
// see "main.cpp"

#endif
