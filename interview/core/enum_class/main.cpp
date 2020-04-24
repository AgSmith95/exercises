#include <iostream>

enum class Color {
    red,
    green,
    blue
};

// can define items "same" names
// due to the fact that Colour is different namespace
enum class Colour {
    red,
    green,
    blue
};

enum Count {
    first,
    second
};

// cannot define items with same names using simple enums
enum Counter {
//    first   // error: ‘first’ conflicts with a previous declaration
              // note: previous declaration ‘List1 first’
//    second, // error: ‘second’ conflicts with a previous declaration
              // note: previous declaration ‘Count second’
    First,
    Second
};

int main() {
    Color c;
//    c = red; // error: ‘red’ was not declared in this scope; did you mean ‘Color::red’
    c = Color::red;
    std::cout << static_cast<int>(c) << '\n'; // 0

    c = Color::green;
    std::cout << static_cast<int>(c) << '\n'; // 1

    c = Color::blue;
    std::cout << static_cast<int>(c) << '\n'; // 2

    Colour C;
    C = Colour::red;
    std::cout << static_cast<int>(C) << '\n'; // 0

    C = Colour::green;
    std::cout << static_cast<int>(C) << '\n'; // 1

    C = Colour::blue;
    std::cout << static_cast<int>(C) << '\n'; // 2

    return 0;
}