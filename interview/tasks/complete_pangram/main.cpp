#include <iostream>
#include <string>
#include <cctype>

std::string getMissingLetters(const std::string& s) {
    auto size = s.size();
    if (size == 0) return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char letters[26] = {};
    for (size_t i = 0; i < size; ++i) {
        if (isalpha(s[i])) {
            ++letters[toupper(s[i]) - 65];
        }
    }

    std::string res;
    for (size_t i = 0; i < 26; ++i) {
        if (letters[i] == 0) {
            res.push_back(static_cast<char>(i + 65));
        }
    }

    return res;
}

int main() {
    std::string s("abc ghi opqrs VWxY");
    std::cout << s << '\n';
    std::cout << getMissingLetters(s) << '\n';
    return 0;
}