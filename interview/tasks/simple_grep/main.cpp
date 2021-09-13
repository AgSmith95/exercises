#include <iostream>
#include <string>
#include <cassert>
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
    auto last_pos = s.rfind(last);
    if (last_pos == std::string::npos || (s.size() - last_pos) > last.size()) {
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

void test_findPattern();

int main() {
    test_findPattern();
}

/*

findPattern("abcdefg", "abc*", wildcardContent) => true, wildcardContent="defg"
findPattern("abcdefg", "*efg", wildcardContent) => true, wildcardContent="abcd"
findPattern("abcdefg", "ab*g", wildcardContent) => true, wildcardContent="cdef"
findPattern("abcdefg", "ab*f", wildcardContent) => false, wildcardContent=""

*/

void test_findPattern() {
    string wildcardContent;
    bool res = false;

    res = findPattern("abcdefg", "abc*", wildcardContent);
    assert(res);
    assert(wildcardContent == "defg");

    res = findPattern("abcdefg", "*efg", wildcardContent);
    assert(res);
    assert(wildcardContent == "abcd");

    res = findPattern("abcdefg", "ab*g", wildcardContent);
    assert(res);
    assert(wildcardContent == "cdef");

    res = findPattern("abcdefg", "ab*f", wildcardContent);
    assert(!res);
    assert(wildcardContent == "");

    res = findPattern("aabcdefg", "ab*f", wildcardContent);
    assert(!res);
    assert(wildcardContent == "");

    res = findPattern("hello world", "hello*", wildcardContent);
    assert(res);
    assert(wildcardContent == " world");

    res = findPattern("hello world world", "*world", wildcardContent);
    assert(res);
    assert(wildcardContent == "hello world ");

    res = findPattern("hello world world", "hello*world", wildcardContent);
    assert(res);
    assert(wildcardContent == " world ");
}
