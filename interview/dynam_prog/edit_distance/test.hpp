#pragma once

#include <iostream>
#include <string>
#include <cassert>

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

void test_rows(const std::string &x, const std::string &y) {
    std::cout << "2rows edit between '" << x << "' and '" << y << "' = ";
    std::cout << edit_distance_two_rows(x.begin(), x.end(), y.begin(), y.end()) << '\n';
    std::cout << "2rows edit between '" << y << "' and '" << x << "' = ";
    std::cout << edit_distance_two_rows(y.begin(), y.end(), x.begin(), x.end()) << '\n';
}

void test_row(const std::string &x, const std::string &y) {
    std::cout << "1row edit between '" << x << "' and '" << y << "' = ";
    std::cout << edit_distance_two_rows(x.begin(), x.end(), y.begin(), y.end()) << '\n';
    std::cout << "1row edit between '" << y << "' and '" << x << "' = ";
    std::cout << edit_distance_two_rows(y.begin(), y.end(), x.begin(), x.end()) << '\n';
}

template<typename It>
bool test_edit_distance(const std::string &x, const std::string &y,
    size_t(method)(It, It, It, It), // method of solving
    size_t dels, size_t inserts, size_t substs)
{
    size_t expected_res =   DELETION_COST * dels +
                            INSERTION_COST * inserts +
                            SUBSTITUTION_COST * substs;
    size_t result = method(x.begin(), x.end(), y.begin(), y.end());
    assert(result == expected_res);

    size_t expected_res_r = DELETION_COST * inserts +
                            INSERTION_COST * dels +
                            SUBSTITUTION_COST * substs;
    size_t result_reversed = method(y.begin(), y.end(), x.begin(), x.end());
    assert(result_reversed == expected_res_r);
	// to not fail on release builds
    return (expected_res == result) && (expected_res_r == result_reversed);
}
