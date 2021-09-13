#include <iostream>
#include <string>
#include <cctype>

char next_char(const char &c) {
    char ret = c;
    while (!isprint(++ret)) ++ret;
    return ret;
}

std::string next_pali(const std::string& pali) {
    std::string ret;

    auto size = pali.size();
    if (size == 0) return ret;

    ret = pali;
    auto r = ret.begin() + size/2;
    auto l = ret.begin() + size/2;

    char tmp = next_char(*r);
    bool next = false;
    if (tmp < *r) {
        next = true;
    }
    *r = tmp;

    if (size % 2 == 0) {
        *--l = *r;
    }

    while (next && r != (ret.end() - 1)) {
        ++r;
        --l;

        tmp = next_char(*r);
        next = false;
        if (tmp < *r) {
            next = true;
        }
        *r = tmp;
        *l = tmp;
    }

    return ret;
}

int main() {
    std::cout << next_pali("a") << '\n';        // b
    std::cout << next_pali("~") << '\n';        // !
    std::cout << next_pali("aa") << '\n';       // bb
    std::cout << next_pali("aba") << '\n';      // aca
    std::cout << next_pali("abba") << '\n';     // acca
    std::cout << next_pali("a~a") << '\n';      // b!b
    std::cout << next_pali("~~") << '\n';       // !!
    std::cout << next_pali("~~~~~") << '\n';    // !!!!!
    return 0;
}