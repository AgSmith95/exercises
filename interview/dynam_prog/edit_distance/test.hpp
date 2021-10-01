#pragma once

#include <iostream>
#include <string>

#include "edit_distance.hpp"

void test_recursive(const std::string &x, const std::string &y) {
    std::cout << "rec edit between '" << x << "' and '" << y << "' = ";
    std::cout << edit_distance_recursive(x.begin(), x.end(), y.begin(), y.end()) << '\n';
    std::cout << "rec edit between '" << y << "' and '" << x << "' = ";
    std::cout << edit_distance_recursive(y.begin(), y.end(), x.begin(), x.end()) << '\n';
}

void test_matrix(const std::string &x, const std::string &y) {
    std::cout << "mat edit between '" << x << "' and '" << y << "' = ";
    std::cout << edit_distance_matrix(x.begin(), x.end(), y.begin(), y.end()) << '\n';
    std::cout << "mat edit between '" << y << "' and '" << x << "' = ";
    std::cout << edit_distance_matrix(y.begin(), y.end(), x.begin(), x.end()) << '\n';
}
