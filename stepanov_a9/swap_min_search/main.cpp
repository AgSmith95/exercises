#include <iostream>

#include "min.h"
#include "max.h"
#include "sort_two.h"

int main() {
    std::cout << min(5,3) << std::endl;
    std::cout << max(3,5) << std::endl;

    int arr[2] = {5,3};
    sort_two(arr[0], arr[1]);
    std::cout << '{' << arr[0] << ' ' << arr[1] << '}' << std::endl;

    return 0;
}