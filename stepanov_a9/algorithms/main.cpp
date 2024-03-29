#include <iostream>
#include <vector>

#include <cassert>

#include "min.h"
#include "max.h"
#include "algorithms.h"
#include "min_element1_2.h"

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
    std::cout << "my minmax_elements:\n";
    std::cout << "    min element [" << *min_max.first << "] is at position <" << std::distance(vec.begin(), min_max.first) << ">\n";
    std::cout << "    max element [" << *min_max.second << "] is at position <" << std::distance(vec.begin(), min_max.second) << ">\n";

    vec = {};
    min_max = minmax_elements_2(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.end());
    assert(min_max.second == vec.end());
    min_max = minmax_elements(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.end());
    assert(min_max.second == vec.end());

    vec = {10};
    min_max = minmax_elements_2(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.begin());
    assert(min_max.second == vec.begin());
    min_max = minmax_elements(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.begin());
    assert(min_max.second == vec.begin());

    vec = {2,2,2,2,2,5,5,5,5,5};
    //std::cout << "vec = { "; for (const auto& e: vec) { std::cout << e << " "; } std::cout << "}\n";
    min_max = minmax_elements_2(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.begin());
    assert(min_max.second == vec.begin()+9);
    min_max = minmax_elements(vec.begin(), vec.end(), std::less());
    assert(min_max.first == vec.begin());
    assert(min_max.second == vec.begin()+9);

    int data[] = {9, 13, 7, 124, 32, 17, 8, 32, 237, 417, 41, 42, 13, 14, 15};
    std::cout << "data = [ "; for (auto x: data) std::cout << x << ' '; std::cout << "]\n";
    int* end = data + sizeof(data)/sizeof(int);
    int* min = min_element_binary(data, end, std::less());
    if (min == end) std::cout << "    NO min_element_binary for data\n";
    else {
        std::cout << "    data min_element_binary = " << *min <<
                  " at position <" << (min - data) << ">\n";
    }

    vec = {4,2,5,1,6,1,8,7,9,3,1,9,1};
    std::cout << "vec = { "; for (const auto& e: vec) { std::cout << e << " "; } std::cout << "}\n";
    min_el = min_element_binary(vec.begin(), vec.end(), std::less());
    if (min_el != vec.end()) {
        std::cout << "    vec min_element_binary = " << *min_el
                  << " at position <" << (min_el - vec.begin()) << ">\n";
    }
    else std::cout << "    NO min_element_binary for vec\n";

    std::cout << "testing min_element1_2 on:\n";
    std::cout << "data = [ "; for (auto x: data) std::cout << x << ' '; std::cout << "]\n";
    end = data + sizeof(data)/sizeof(int);
    std::pair<int*, int*> min1_2 = min_element1_2(data, end, std::less());
    if (min1_2.first == end) {
        std::cout << "    No elements\n";
    }
    else {
        std::cout << "    Min is " << *(min1_2.first) << " " << *(min1_2.second) << '\n';
    }

    return 0;
}