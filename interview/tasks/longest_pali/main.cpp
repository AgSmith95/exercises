#include <iostream>
#include <algorithm>
#include <string>

template<typename It>
bool isPalindrome(It first, It last) {
    if (first >= last) return false;
    --last;
    while (first <= last) {
        if (*first != *last) {
            return false;
        }
        ++first;
        --last;
    }
    return true;
}

std::string longestPalindrome(const std::string& s) {
    std::string ret;
    if (s.empty()) return ret;
    if (s.size() == 1) {
        ret = s;
        return ret;
    }

    auto posl = s.begin();
    auto posr = posl + 1;
    decltype(std::distance(posl, posr)) max_len = 1;

    decltype(max_len) len = 1;
    for (auto left = s.begin(); left != s.end(); ++left) {
        for (auto right = s.end(); right != left; --right) {
            if (isPalindrome(left, right)) {
                len = std::distance(left, right);
                if (len > max_len) {
                    posl = left;
                    posr = right;
                    max_len = len;
                }
            }
        }
    }

    ret = std::string(posl, posr);
    return ret;
}

int main() {
    std::string s;
    std::string ret;

    ret = longestPalindrome(s);
    std::cout << ret << std::endl;

    s = "X";
    ret = longestPalindrome(s);
    std::cout << ret << std::endl;

    s = "Xyz";
    ret = longestPalindrome(s);
    std::cout << ret << std::endl;

    s = "XX";
    ret = longestPalindrome(s);
    std::cout << ret << std::endl;

    s = "yXXy";
    ret = longestPalindrome(s);
    std::cout << ret << std::endl;

    s = "abcaabbbaakl";
    ret = longestPalindrome(s);
    std::cout << ret << std::endl;

    s = "abcaabbbaaklXnbglkfzzfklgbnXisjdnbsinvbojnon";
    ret = longestPalindrome(s);
    std::cout << ret << std::endl;

    std::cout << longestPalindrome("sonbjnfubabjlolkjbabcaabbbaakljbsiodbjbdxpjbijbvbhu") << std::endl;

    return 0;
}
