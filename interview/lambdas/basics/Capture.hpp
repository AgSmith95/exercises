#ifndef LAMBDAS_BASICS_CAPTURE_HPP
#define LAMBDAS_BASICS_CAPTURE_HPP

#include <iostream>

/**
 *          Stroustrup The C++ Prog. Lang. 4ed Part 11.4.3 Capture:
 * 1. []: an empty capture list. This implies that no local names from the surrounding context can
 *      be used in the lambda body. For such lambda expressions, data is obtained from arguments
 *      or from nonlocal variables.
 * 2. [&]: implicitly capture by reference. All local names can be used. All local variables are
 *      accessed by reference.
 * 3. [=]: implicitly capture by value. All local names can be used. All names refer to copies of
 *      the local variables taken at the point of call of the lambda expression.
 * 4. [capture-list]: explicit capture; the capture-list is the list of names of local variables to be
 *      captured (i.e., stored in the object) by reference or by value. Variables with names preceded
 *      by & are captured by reference. Other variables are captured by value. A capture list can
 *      also contain this and names followed by ... as elements.
 * 5. [&, capture-list]: implicitly capture by reference all local variables with names not mentioned in the list. The capture list can contain this. Listed names cannot be preceded by &.
 *      Variables named in the capture list are captured by value.
 * 6. [=, capture-list]: implicitly capture by value all local variables with names not mentioned in
 *      the list. The capture list cannot contain this. The listed names must be preceded by &. Variables named in the capture list are captured by reference.
 *
 */

void two() {
    int x{10};
    auto lambda1 = [&](int a) {
        x += a;
        return x;
    };
    std::cout << lambda1(1) << ' ';
    auto lambda2 = [&x](int a) {    // part of [4]
        x += a;
        return x;
    };
    std::cout << lambda2(1) << '\n';
}

void three() {
    int x{100};
    auto lambda1 = [=](int a) {
        // x += a; // error, because x is not captured by reference
        return x + a;
    };
    std::cout << lambda1(10) << ' ';
    auto lambda2 = [x](int a) {     // part of [4]
        // x += a; // error, because x is not captured by reference
        return x + a;
    };
    std::cout << lambda2(10) << '\n';
}

void fivesix() {
    int x{1000}, y{100};
    auto lambda1 = [&, y](int a) {     // & cannot precede a capture, when the capture default is '&'
        // y += a; //  // error, because y is not captured by reference
        x += a + y;
        return x;
    };
    std::cout << lambda1(10) << ' ';
    auto lambda2 = [=, &y](int a) {     // & must precede a capture, when the capture default is '='
        // x += a; // error, because x is not captured by reference
        y += a + x;
        return y;
    };
    std::cout << lambda2(10) << '\n';
}

#endif //LAMBDAS_BASICS_CAPTURE_HPP
