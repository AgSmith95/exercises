#include <iostream>

const char* s = "Narrow multibyte string literal. Line1\n"
                "Line2\n";
const wchar_t* ws = L"wide string literal\n";
//                                         this garbage means HELLO in russian
auto u8 = u8"UTF-8 encoded string literal: \u041F\u0420\u0418\u0412\u0415\u0422 \n";
// this auto means:
//   const char[N] (until C++20)
//   const char8_t[N] (since C++20)
const char16_t* u16 = u"UTF-16 encoded string literal\n";
const char32_t* u32 = U"UTF-32 encoded string literal\n";

// 1. Raw string literals
auto raw1 = R"(Raw string literal. Line 1.
Without delim/prefix. Line 2.
\n-s Not needed. Line 3
)";
// 2. Delimiter in raw string literal
//auto raw2 = R"(put ')"' here)"; // error: missing terminating ' character
                                  // auto raw2 = R"(put ')"' here)";
auto raw2 = R"raw2(put ')"' here)raw2";
// 3. Prefix in raw string literal
auto u8Rs = u8R"(UTF-8 encoded string literal: )" u8"\u041F\u0420\u0418\u0412\u0415\u0422 \n";

int main() {
    std::cout << "s: " << s << '\n';
    std::cout << "ws: " << ws << '\n';
    std::cout << "u8: " << u8 << '\n';
    std::cout << "u16: " << u16 << '\n';
    std::cout << "u32: " << u32 << '\n';

    std::cout << '\n';

    std::cout << "raw1: " << raw1 << '\n';
    std::cout << "raw2: " << raw2 << '\n';
    std::cout << "u8Rs: " << u8Rs << '\n';
    return 0;
}