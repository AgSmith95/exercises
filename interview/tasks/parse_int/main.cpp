#include <iostream>
#include <climits> // the only thing really used in implementation
#include <cassert>
#include <string>

int parse_int_naive(const char* s) {
    int res = 0;
    // for now it doesn't cover very long numbers
    while ((*s >= '0') && (*s <= '9')) {
        res = 10*res + static_cast<int>(*s - '0'); // undefined behavior
        // UB, because of "signed integer overflow"
        // signed integers are not guaranteed to be twos-complement on every architecture
        ++s;
    }
    return res;
}

int parse_int(const char* s) {
    int res = 0;
    int val = 0;
    while ((*s >= '0') && (*s <= '9')) {
        val = static_cast<int>(*s - '0');
        if (res <= (INT_MAX - val)/10) { // I don't like it
        // too much unnecessary operations here
            res = 10 * res + val;
        }
        else {
            return res;
        }
        ++s;
    }
    return res;
}

int main() {
    assert(parse_int("") == 0);
    std::cout << parse_int("") << '\n';

    assert(parse_int("123") == 123);
    std::cout << parse_int("123") << '\n';

    assert(parse_int("123a") == 123);
    std::cout << parse_int("123a") << '\n';

    assert(parse_int("000123") == 123);
    std::cout << parse_int("000123") << '\n';

    assert(parse_int("linux") == 0);
    std::cout << parse_int("linux") << '\n';

    assert(parse_int("-5") == 0);
    std::cout << parse_int("-5") << '\n';

    std::string tmp_s{std::to_string(INT_MAX)};
    std::cout << "tmp_s - " << tmp_s << '\n';
    assert(parse_int(tmp_s.c_str()) == INT_MAX);
    std::cout << parse_int(tmp_s.c_str()) << '\n';

    tmp_s += "000a00";
    assert(parse_int(tmp_s.c_str()) == INT_MAX);
    std::cout << parse_int(tmp_s.c_str()) << '\n';
    return 0;
}
