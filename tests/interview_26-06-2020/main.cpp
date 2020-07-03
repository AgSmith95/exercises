/**
 * lib func
 * do not use other libs
 * core c++ only // no #include <...>
 * math-like func: well define value for any input f(x)
 * one input - one output
 *
 * web-shop
 * shop has front/end
 * checkout basket before order
 * row for each product
 * quantity for each product
 * string -> sent to server
 * func parse string and return int
 *
 * "123" -> 123
 * "12A" -> 12
 *
 * start parse from the left
 * parse only numbers
 * terminate on first wrong char
 * wrong char is anything except [0-9]
 *
 * " 123" -> 0
 *
 * "" -> 0
 *
 * No extra work on str length
 */

#include <climits>

int parse_input(const char* s) {
    int res = 0;
    int val = 0;
    while ((*s >= '0') && (*s <= '9')) {
        val = static_cast<int>(*s - '0');
        if (res <= (INT_MAX - val)/10) {
            res = 10 * res + val;
        }
        else {
            return res;
        }
        ++s;
    }
    return res;
}

int parse_input_naive(const char* s) {
    int res = 0;
    while ((*s >= '0') && (*s <= '9')) {
        res = 10*res + static_cast<int>(*s - '0');
        ++s;
    }
    return res;
}

int main() {
    parse_input("123");
    return 0;
}
