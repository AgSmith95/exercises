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

    std::cout << "Recursive 'BCDE'-'BDF'-'BCDE': ";
    std::cout << edit_distance_recursive(X.begin(), X.end(), Y.begin(), Y.end()) <<  ' '; // 0 1 2
    std::cout << edit_distance_recursive(Y.begin(), Y.end(), X.begin(), X.end()) << '\n'; // 1 0 2
    test_edit_distance("hello", "", edit_distance_recursive<std::string::const_iterator>, 0, 5, 0);
    test_edit_distance("hello", "low", edit_distance_recursive<std::string::const_iterator>, 3, 1, 0);
    test_edit_distance("hello", "holy", edit_distance_recursive<std::string::const_iterator>, 2, 0, 1);
    test_edit_distance("kitten", "sitting", edit_distance_recursive<std::string::const_iterator>, 0, 1, 2);
    test_edit_distance("intention", "execution", edit_distance_recursive<std::string::const_iterator>, 0, 0, 5);
    test_edit_distance("abc", "ef", edit_distance_recursive<std::string::const_iterator>, 0, 1, 2);


    std::cout << "\n";
    std::cout << "Matrix 'BCDE'-'BDF'-'BCDE': ";
    std::cout << edit_distance_matrix(X.begin(), X.end(), Y.begin(), Y.end()) <<  ' '; // 0 1 2
    std::cout << edit_distance_matrix(Y.begin(), Y.end(), X.begin(), X.end()) << '\n'; // 1 0 2
    test_edit_distance("hello", "", edit_distance_matrix<std::string::const_iterator>, 0, 5, 0);
    test_edit_distance("hello", "low", edit_distance_matrix<std::string::const_iterator>, 3, 1, 0);
    test_edit_distance("hello", "holy", edit_distance_matrix<std::string::const_iterator>, 2, 0, 1);
    test_edit_distance("kitten", "sitting", edit_distance_matrix<std::string::const_iterator>, 0, 1, 2);
    test_edit_distance("intention", "execution", edit_distance_matrix<std::string::const_iterator>, 0, 0, 5);
    test_edit_distance("abc", "ef", edit_distance_matrix<std::string::const_iterator>, 0, 1, 2);

    std::cout << "\n";
    std::cout << "2Rows 'BCDE'-'BDF'-'BCDE': ";
    std::cout << edit_distance_two_rows(X.begin(), X.end(), Y.begin(), Y.end()) <<  ' '; // 0 1 2
    std::cout << edit_distance_two_rows(Y.begin(), Y.end(), X.begin(), X.end()) << '\n'; // 1 0 2
    test_edit_distance("hello", "", edit_distance_two_rows<std::string::const_iterator>, 0, 5, 0);
    test_edit_distance("hello", "low", edit_distance_two_rows<std::string::const_iterator>, 3, 1, 0);
    test_edit_distance("hello", "holy", edit_distance_two_rows<std::string::const_iterator>, 2, 0, 1);
    test_edit_distance("kitten", "sitting", edit_distance_two_rows<std::string::const_iterator>, 0, 1, 2);
    test_edit_distance("intention", "execution", edit_distance_two_rows<std::string::const_iterator>, 0, 0, 5);
    test_edit_distance("abc", "ef", edit_distance_two_rows<std::string::const_iterator>, 0, 1, 2);

    std::cout << "\n";
    std::cout << "1Row 'BCDE'-'BDF'-'BCDE': ";
    std::cout << edit_distance_one_row(X.begin(), X.end(), Y.begin(), Y.end()) <<  ' '; // 0 1 2
    std::cout << edit_distance_one_row(Y.begin(), Y.end(), X.begin(), X.end()) << '\n'; // 1 0 2
    test_edit_distance("hello", "", edit_distance_one_row<std::string::const_iterator>, 0, 5, 0);
    test_edit_distance("hello", "low", edit_distance_one_row<std::string::const_iterator>, 3, 1, 0);
    test_edit_distance("hello", "holy", edit_distance_one_row<std::string::const_iterator>, 2, 0, 1);
    test_edit_distance("kitten", "sitting", edit_distance_one_row<std::string::const_iterator>, 0, 1, 2);
    test_edit_distance("intention", "execution", edit_distance_one_row<std::string::const_iterator>, 0, 0, 5);
    test_edit_distance("abc", "ef", edit_distance_one_row<std::string::const_iterator>, 0, 1, 2);

    return 0;
}