/*
Can you "build" a number from other numbers

If you have all of the numbers - you can build anything
You can duplicate numbers
Overlaps/duplications don't matter on both sides

canBeBuilt(1234, {4, 2, 3, 1}) => true
canBeBuilt(1001, {1, 0}) => true
canBeBuilt(123, {3, 21}) => true
canBeBuilt(123, {3, 1}) => false


I think this one was my attempt but I haven't fully
understood the original task

This looks kinda crazy
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

unsigned find_digits(unsigned n) {
    unsigned ret = 0;
    if (n == 0) {
        return 1;
    }
    while (n != 0) {
        ret |= 1 << (n%10);
        n /= 10;
    }
    return ret;
}

bool LEGO(unsigned n, const std::vector<unsigned>& v) {
    if (v.empty()) return false;

    unsigned digits_n;
    unsigned digits_v = 0;

    digits_n = find_digits(n);
    auto it = v.begin();
    while (digits_v < 0b1111111111 && it != v.end()) {
        digits_v |= find_digits(*it);
        ++it;
    }

    // dn = 0b 0101001110
    // dv = 0b 1101101110
    return (digits_n & digits_v) == digits_n;
}

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

    assert(LEGO(1234, {2376, 145809, 87976, 214155, 35438390}));

    assert(LEGO(1, {1234567890}));
    assert(LEGO(12, {1234567890}));
    assert(LEGO(213, {1234567890}));
    assert(LEGO(4123, {1234567890}));
    assert(LEGO(35142, {1234567890}));
    assert(LEGO(514623, {1234567890}));
    assert(LEGO(5732461, {1234567890}));
	
    assert(LEGO(77777777, {7}));
    return 0;
}
