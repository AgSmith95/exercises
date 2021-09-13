#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>

unsigned digits_count(unsigned n) {
    if (n == 0) return 1;
    else return (int)log10((double)n) + 1;
}

bool concat_to_num(const char *s, unsigned n, const std::vector<std::string>& v) {
    if (n == 0) return true;
    else if (v.empty()) return false;

    bool ret = false;
    const char *pos = s;
    for (const auto& el: v) {
        pos = s;
        do {
            ret = false;
            if (el.size() > n) {
                pos = nullptr;
                continue;
            }

            pos = strstr(pos, el.c_str());
            if (pos && pos < (s+n)) {
                ret = true;
                if (pos != s) ret &= concat_to_num(s, pos - s, v);
                ret &= concat_to_num(pos + el.size(), n - (pos - s) - el.size(), v);
            }
            if (ret) break;
            if (pos) pos += el.size();
        } while (pos && pos < (s+n));

        if (ret) break;
    }
    return ret;
}

int main() {
    const char *s = "";
    std::vector<std::string> v;

    assert(concat_to_num(s, strlen(s), v));

    s = "0";
    assert(!concat_to_num(s, strlen(s), v));

    s = "545";
    v = {"2", "3", "4", "5"};
    assert(concat_to_num(s, strlen(s), v));

    s = "45";
    assert(concat_to_num(s, strlen(s), v));

    s = "10";
    v = {"100", "10"};
    assert(concat_to_num(s, strlen(s), v));

    s = "1001";
    v = {"100", "10"};
    assert(!concat_to_num(s, strlen(s), v));

    s = "8215243";
    v = {"52", "14", "3", "82", "4", "1"};
    assert(concat_to_num(s, strlen(s), v));

    s = "8215243";
    v = {"52", "3", "82", "4", "1"};
    assert(concat_to_num(s, strlen(s), v));

    return 0;
}