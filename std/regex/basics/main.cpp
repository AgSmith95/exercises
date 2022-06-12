#include <iostream>
#include <regex>
//#include <string>

int main() {
    //                 0123456789012345678901234567890
    const char* str1 = "9 [SYM.NGD] some1-code2-xyz 13";
    const char* str2 = "9 [SYMwNGD] some1-code2-xyz 13";
    std::cout << "str1 = '''" << str1 << "'''\n";
    std::cout << "str2 = '''" << str2 << "'''\n";
    std::cout << '\n';

    std::regex re1(".*SYM.NGD.*", std::regex_constants::extended);
    std::regex re2("SYM.NGD", std::regex_constants::extended);

    std::cmatch cm1; // std::match_results<const char*>
    std::cmatch cm2;

    std::regex_match(str1, cm1, re1);
    std::cout << "re1 in str1 starts at pos " << cm1.position() << '\n'; // 0
    std::cout << "regex_match(str2, re1) = " << std::regex_match(str2, re1) << '\n'; // 1 (true)
    // match, because . is any char
    std::cout << "regex_match(str2, re2) = " << std::regex_match(str2, re2) << '\n'; // 0 (false)
    // doesn't match because regex_match matches the whole string

    std::cout << '\n';

    std::regex_search(str1, cm2, re2);
    std::cout << "re2 in str1 starts at pos " << cm2.position() << '\n'; // 0
    std::cout << "regex_search(str2, re1) = " << std::regex_search(str2, re1) << '\n'; // 1 (true)
    std::cout << "regex_search(str2, re2) = " << std::regex_search(str2, re2) << '\n'; // 1 (true)

    return 0;
}