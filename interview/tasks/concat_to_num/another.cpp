#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void find_digits(unsigned n, bool *digits) {
    if (n == 0) digits[0] = true;
    while (n != 0) {
        digits[n % 10] = true;
        n /= 10;
    }
}

bool LEGO(unsigned n, const std::vector<unsigned>& v) {
    bool digits_n[10] = {};
    bool digits_v[10] = {};

    find_digits(n, digits_n);
    for (const auto& el: v) find_digits(el, digits_v);

    bool ret = !v.empty();
    for (int i = 0; i < 10; ++i) ret &= !digits_n[i] | digits_v[i];

    return ret;
}

/*
canBeBuilt(1234, {4, 2, 3, 1}) => true
canBeBuilt(1001, {1, 0}) => true
canBeBuilt(123, {3, 21}) => true
canBeBuilt(123, {3, 1}) => false
*/

int main() {
    // testcases given
    assert(LEGO(1234, {4,2,3,1}));
    assert(LEGO(1001, {1,0}));
    assert(LEGO(123, {3,21}));
    assert(!LEGO(123, {3,1}));

    // testcases mine
    assert(!LEGO(0, {}));
    assert(LEGO(0, {0}));
    assert(!LEGO(1, {0}));
    assert(LEGO(1, {1}));
    assert(LEGO(21, {2,1}));
    assert(LEGO(21, {12}));
    assert(LEGO(21, {21}));
    assert(!LEGO(21, {2}));
    assert(LEGO(213, {21,3}));
    assert(!LEGO(213, {3}));
    assert(!LEGO(213, {2,3}));
    assert(!LEGO(213, {1,3}));
    assert(!LEGO(213, {1,2}));
    return 0;
}