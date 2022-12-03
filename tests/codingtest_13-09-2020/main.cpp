#include <iostream>
#include <vector>

#include "one.h"

int main() {
    std::cout << "test 13-09-2020\n";

    std::cout << "===== PART ONE =====\n";
    gridvec grid = {{1,1,0,0},{0,0,1,0},{0,0,0,0},{1,0,1,1},{1,1,1,1}};
    for (const auto & row : grid) {
        for (const auto& el : row) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }

    std::cout << '\n';
    std::cout << numTruck(grid) << '\n';

    std::cout << "===== PART TWO =====\n";
    return 0;
}