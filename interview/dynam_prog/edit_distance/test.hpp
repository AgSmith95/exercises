#pragma once

#include <iostream>
#include <string>

#include "edit_distance.hpp"

void test_recursive(const std::string &x, const std::string &y) {
    std::cout << "edit between '" << x << "' and '" << y << "' = ";
    std::cout << edit_distance_recursive(x.begin(), x.end(), y.begin(), y.end()) << '\n';
    std::cout << "edit between '" << y << "' and '" << x << "' = ";
    std::cout << edit_distance_recursive(y.begin(), y.end(), x.begin(), x.end()) << '\n';
}
