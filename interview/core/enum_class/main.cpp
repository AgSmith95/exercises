#include <iostream>

enum class Color {
    red,
    green,
    blue
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

    return 0;
}