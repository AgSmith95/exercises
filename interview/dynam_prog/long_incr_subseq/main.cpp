#include <iostream>
#include <vector>

#include "longest_increasing_subsequence.hpp"

int main() {
    std::vector<int> vi = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    auto res = longest_increasing_subsequence(vi.begin(), vi.end());
    std::cout << res.size() << ": ";
    print_container(res.begin(), res.end());

    std::cout << longest_increasing_subsequence_num(vi.begin(), vi.end()) << '\n';

    auto res_dynam = longest_increasing_subsequence_dynamic(vi.begin(), vi.end());
    std::cout << res_dynam.size() << ": ";
    print_container(res_dynam.begin(), res_dynam.end());

    std::cout << lis_nlogn_num(vi.begin(), vi.end()) << '\n';
    return 0;
}