// g++ -std=c++17 copy.exe -o copy

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

#define INIT \
        std::cout << '\n';\
        vs num{Nums};\
        vs str{Strs}; 

using vs = std::vector<std::string>;

const vs Nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
const vs Strs = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

// (std::copy + std::ostream_iterator) example
template <class Container>
void writeToCout(const Container& c, const char* delim = " ") {
    std::copy(c.begin(), c.end(), 
        std::ostream_iterator<typename Container::value_type>(std::cout, delim));
    std::cout << '\n';
}

int main() {
    // test if writeToCout works
    {
        INIT

        writeToCout(num);
        writeToCout(str);
    }
    // simple copy
    {
        INIT

        std::copy(str.begin() + 3, str.begin() + 7, num.begin() + 3);
        writeToCout(num);
        // 0 1 2 three four five six 7 8 9
    }
    // overlap
    {
        INIT

        std::copy(num.begin() + 3, num.begin() + 7, num.begin() + 4);
        writeToCout(num);
        // 0 1 2   3 3 3 3 3   8 9
    }
    // copy_n
    {
        INIT

        std::copy_n(str.begin() + 3, 4, num.begin() + 3);
        writeToCout(num);
        // 0 1 2 three four five six 7 8 9
    }
    // copy_backward
    {
        INIT

        std::copy_backward(num.begin() + 3, num.begin() + 6, num.begin() + 7);
        writeToCout(num);
        // 0 1 2 3 3 4 5 7 8 9
    }
    // copy_if
    {
        INIT

        std::copy_if(str.begin(), str.end(), num.begin(), [](const std::string& s){ return s.length() > 3; });
        writeToCout(num);
        // zero three four five seven eight nine 7 8 9
    }
    // move
    {
        INIT

        std::move(str.begin() + 2, str.begin() + 5, num.begin() + 2);
        writeToCout(num, " | ");
        writeToCout(str, " | ");
        // 0 | 1 | two | three | four | 5 | 6 | 7 | 8 | 9 |
        // zero | one |  |  |  | five | six | seven | eight | nine |
    }
    // move if through copy_if
    {
        INIT

        std::copy_if(std::make_move_iterator( str.begin() ), std::make_move_iterator( str.end() ), 
                     num.begin(), [](const std::string& s){ return s.length() > 4; });
        writeToCout(num, " | ");
        writeToCout(str, " | ");
        // three | seven | eight | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
        // zero | one | two |  | four | five | six |  |  | nine |
    }
    // swap_ranges
    {
        INIT

        std::swap_ranges(str.begin() + 3, str.begin() + 7, num.begin() + 3);
        writeToCout(num);
        writeToCout(str);
        // 0 1 2 three four five six 7 8 9
        // zero one two 3 4 5 6 seven eight nine
    }
    // copy_n from cin to cout
    {
        std::cout << "\ninput 5 strings: ";
        std::copy_n(std::istream_iterator<std::string>(std::cin), 5, 
                    std::ostream_iterator<std::string>(std::cout, " "));
    }
}