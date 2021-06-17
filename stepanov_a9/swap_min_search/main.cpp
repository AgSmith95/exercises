#include <iostream>
#include <vector>

#include <cassert>

#include "min.h"
#include "max.h"
#include "algorithms.h"

int main() {
    assert(min(5,3) == 3);
    assert(min(3,3) == 3);
    assert(min(3,5) == 3);

    assert(max(3,5) == 5);
    assert(max(5,5) == 5);
    assert(max(5,3) == 5);

    int arr[2] = {5,3};
    sort_two(arr[0], arr[1]);
    std::cout << '{' << arr[0] << ' ' << arr[1] << '}' << std::endl;

    std::vector<int> vec = {4,2,5,1,6,1,8,7,9,3,1,9,1};
    std::cout << "vec = { "; for (const auto& e: vec) { std::cout << e << " "; } std::cout << "}\n";
    auto min_el = ::min_element(vec.begin(), vec.end(), std::less());
    std::cout << "min_el in vec = " << *min_el << "\n";

    auto min_max = minmax_elements_2(vec.begin(), vec.end(), std::less());
    std::cout << "min element [" << *min_max.first << "] is at position <" << std::distance(vec.begin(), min_max.first) << ">\n";
    std::cout << "max element [" << *min_max.second << "] is at position <" << std::distance(vec.begin(), min_max.second) << ">\n";

    vec = {};
    min_max = minmax_elements_2(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.end());
    assert(min_max.second == vec.end());

    vec = {10};
    min_max = minmax_elements_2(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.begin());
    assert(min_max.second == vec.begin());

    vec = {2,2,2,2,2,5,5,5,5,5};
    std::cout << "vec = { "; for (const auto& e: vec) { std::cout << e << " "; } std::cout << "}\n";
    min_max = minmax_elements_2(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.begin());
    assert(min_max.second == vec.begin()+9);

    return 0;
}