#include <iostream>

#include <cassert>

#include "min.h"
#include "max.h"
#include "sort_two.h"

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

    int vec[] = {4,2,5,1,6,8,7,9,3};
    std::cout << "vec = { "; for (const auto& e: vec) { std::cout << e << " "; } std::cout << "}\n";
    auto min_el = ::min_element(vec, vec + 9, std::less());
    std::cout << "min_el in vec = " << *min_el << "\n";

    return 0;
}