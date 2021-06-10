#include <iostream>
#include <string>
using namespace std;

bool findPattern(const string& s, const string& pattern, string& wildcardContent) {
    if (s.empty()) {
        if (!pattern.empty()) {
            return false;
        }
        else {
            wildcardContent = "";
            return true;
        }
    }

    auto asterisk = pattern.find('*');
    if (asterisk == std::string::npos) {
        wildcardContent = "";
        return s == pattern;
    }

    string first(pattern, 0, asterisk);
    string last(pattern, asterisk + 1);

    if (s.find(first) != 0) {
        wildcardContent = "";
        return false;
    }
    auto last_pos = s.find(last, asterisk + 1);
    if (!last.empty() && (last_pos == std::string::npos || (s.size() - last_pos) > last.size())) {
        wildcardContent = "";
        return false;
    }

    if (asterisk != pattern.size() - 1) {
        wildcardContent = std::string(s, asterisk, last_pos - asterisk);
    }
    else {
        wildcardContent = std::string(s, asterisk);
    }
    return true;
}

/*

findPattern("abcdefg", "abc*", wildcardContent) => true, wildcardContent="defg"
findPattern("abcdefg", "*efg", wildcardContent) => true, wildcardContent="abcd"
findPattern("abcdefg", "ab*g", wildcardContent) => true, wildcardContent="cdef"
findPattern("abcdefg", "ab*f", wildcardContent) => false, wildcardContent=""

*/

int main() {
    string wildcardContent;

    std::cout << findPattern("abcdefg", "abc*", wildcardContent) << " ";
    std::cout << '"' << wildcardContent << "\"\n";

    std::cout << findPattern("abcdefg", "*efg", wildcardContent) << " ";
    std::cout << '"' << wildcardContent << "\"\n";

    std::cout << findPattern("abcdefg", "ab*g", wildcardContent) << " ";
    std::cout << '"' << wildcardContent << "\"\n";

    std::cout << findPattern("abcdefg", "ab*f", wildcardContent) << " ";
    std::cout << '"' << wildcardContent << "\"\n";

    std::cout << findPattern("aabcdefg", "ab*f", wildcardContent) << " ";
    std::cout << '"' << wildcardContent << "\"\n";

    std::cout << findPattern("hello world", "hello*", wildcardContent) << " ";
    std::cout << '"' << wildcardContent << "\"\n";
}
