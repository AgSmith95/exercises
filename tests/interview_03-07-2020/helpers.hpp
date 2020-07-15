#ifndef PROJECT_HELPERS_HPP
#define PROJECT_HELPERS_HPP

#include <iostream>
#include <ostream>
#include <iomanip>
#include <iterator>
#include <random>
#include <algorithm>

// (std::copy + std::ostream_iterator) example
template <class Container>
void writeToOut(const Container& c, std::ostream& out = std::cout) {
    for(const auto& item: c) {
        out << std::setw(6) << item;
    }
//    std::cout << '\n';
}

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<int> distrib(1, 1000);

std::uniform_int_distribution<int> distrib_diff(0, 100);
std::vector<int> generate(size_t size, size_t pos) {
    if (size < pos) {
        std::swap(size, pos);
    }
    else if (pos == size) {
        pos -= 1;
    }
    size_t i = 0;
    int val = distrib(gen);
    int diff;
    std::vector<int> v(size);
    for(; i <= pos; ++i) {
        diff = distrib_diff(gen);
        if ((diff % 5) == 4) { // this way there are a lot of duplicates
            val -= diff;
        }
        v[i] = val;
    }
    for(; i < size; ++i) {
        diff = distrib_diff(gen);
        if ((diff % 5) == 4) { // this way there are a lot of duplicates
            val += diff;
        }
        v[i] = val;
    }
    return v;
}

#endif //PROJECT_HELPERS_HPP
