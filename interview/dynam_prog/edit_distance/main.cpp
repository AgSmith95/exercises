#include <iostream>
#include <vector>
#include <string>

#include "edit_distance.hpp"
#include "test.hpp"

/**
 * The Levenshtein distance between two words is the minimum number of single-character
 *      edits (i.e., insertions, deletions, or substitutions) required to
 *      change one word into the other. Each of these operations has a unit cost.
 *
 * kitten —> sitten (substitution of s for k)
 * sitten —> sittin (substitution of i for e)
 * sittin —> sitting (insertion of g at the end)
 */

int main() {
    std::vector<char> X = {'B','C','D','E'};
    std::vector<char> Y = {'B','D','F'};

    std::cout << "\n\n";
    std::cout << edit_distance_recursive(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 2
    std::cout << edit_distance_recursive(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 2
    test_recursive("hello", "");     // 5 5
    test_recursive("hello", "low");  // 4 4
    test_recursive("hello", "holy"); // 3 3


    std::cout << "\n\n";
    std::cout << edit_distance_matrix(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 2
    std::cout << edit_distance_matrix(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 2
    test_matrix("hello", ""); // 5 5
    test_matrix("hello", "low"); // 4 4
    test_matrix("hello", "holy"); // 3 3
    test_matrix("intention", "execution"); // 5 5
    test_matrix("kitten", "sitting"); // 3 3
    test_matrix("abc", "ef"); // 3 3

    std::cout << "\n\n";
    std::cout << edit_distance_two_rows(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 2
    std::cout << edit_distance_two_rows(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 2
    test_rows("hello", ""); // 5 5
    test_rows("hello", "low"); // 4 4
    test_rows("hello", "holy"); // 3 3

    std::cout << "\n\n";
    std::cout << edit_distance_one_row(X.begin(), X.end(), Y.begin(), Y.end()) << "\n"; // 2
    std::cout << edit_distance_one_row(Y.begin(), Y.end(), X.begin(), X.end()) << "\n"; // 2
    test_row("hello", ""); // 5 5
    test_row("hello", "low"); // 4 4
    test_row("hello", "holy"); // 3 3

    return 0;
}