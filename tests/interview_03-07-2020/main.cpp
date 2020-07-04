/**
 * no compiler/debugger/web
 *
 * std::vector<T>
 * T is less comparable
 * vector sorted by less operator of T
 *
 * vector parameters:
 * 1st part go down
 * 2nd part - up
 *
 * in between there is a minimum
 *
 * job is to find the minimum
 *
 * dont waste time/memory
 * write as simple and as elegant as possible
 */

// sort of:
// bool operator<(const T& l, const T& r) { return l < r; }
// 5 < 8    true
// !(5 < 8) == 5 >= 8   false
// 3 < 3 false; !(3 < 3) true;

// examples:
// 10 5 1 5 10
// 10 3 1 5 7
// 10 9 8 7 6 5 4 3 3 3 4 5 6 7 8
// 10 7 5 3 3 9 9 9 11
// 10 7 5 5 5 3 3 9 9 9 11
// the worst case I can think of:
// 12 10 7 5 5 5 3 3 3 5 5 5 10 11 13
// 5 5 5 3 3 3 5 5 5

#include <vector>

template <typename T>
bool less_or_equal(const T& l, const T& r) {
    if (l < r) {
        return true;
    }
    return !(r < l);
}

template <typename T>
T find_min(const std::vector<T>& v) {
    size_t i = v.size() - 1;
    while ( (i != 0) && less_or_equal(v[i - 1], v[i]) ) {
        --i;
    }
    return v[i];
}

#include <iostream>

int main() {
    std::cout << find_min<int>({5,4,3,2,2,2,1,1,1,2,2,2,2,3,4,5}) << '\n';
    std::cout << find_min<int>({10,9,8,7}) << '\n';
    std::cout << find_min<int>({10,9,8,7,8,9}) << '\n';
    std::cout << find_min<int>({10,9,8,7,7,7,8,9}) << '\n';
    std::cout << find_min<int>({5,5,5,3,3,3,5,5,5}) << '\n';
    std::cout << find_min<int>({1,2,3}) << '\n';
    std::cout << find_min<int>({99}) << '\n';
    std::cout << find_min<int>({-10,-11,-12,-13,-13,-13,-15,-15,-15,-13,-13,-13,-10,-5,-3}) << '\n';
    return 0;
}
