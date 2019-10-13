#include <iostream>
#include <string>
#include <vector>

typedef ushort ushort;
typedef std::vector<ushort> tower;

unsigned int Height = 2;
std::vector<tower>* Towers;

static long turn = 0;
void print_hanoi(const ushort height,
                 const tower& left,
                 const tower& middle,
                 const tower& right) {
    for(size_t i = height; i > 0; --i) {
        std::string s;
        // left
        if (left.size() >= i) {
            s += std::string(left[i-1], '*') + std::string(height - left[i-1], ' ');
        } else {
            s += std::string(height, ' ');
        }
        s += " | ";
        // middle
        if (middle.size() >= i) {
            s += std::string(middle[i-1], '*') + std::string(height - middle[i-1], ' ');
        } else {
            s += std::string(height, ' ');
        }
        s += " | ";
        // right
        if (right.size() >= i) {
            s += std::string(right[i-1], '*') + std::string(height - right[i-1], ' ');
        } else {
            s += std::string(height, ' ');
        }
        std::cout << s << '\n';
    }
    std::cout << std::string(height*3 + 2*3, '-') << " [" << ++turn << "]\n";
}

void solve_hanoi(ushort height,
           tower& left,
           tower& middle,
           tower& right) {
    if (height > 0) {
        // 1) move N-1 from  right to middle [recursively]
        solve_hanoi(height-1, left, right, middle);
        // 2) move   1 from   left to  right
        right.emplace_back(left.back());
        left.pop_back();
        print_hanoi(Height, Towers->at(0), Towers->at(1), Towers->at(2));
        // 3) move N-1 from middle to  right [recursively]
        solve_hanoi(height-1, middle, left, right);
    }
}

void init_hanoi(ushort height,
                tower& left) {
    turn = -1;
    for(unsigned int i = 0; i < height; ++i) {
        left.emplace_back(height-i);
    }
}

int main() {
    std::cout << "Input Height (default 2): ";
    std::cin >> Height;
    std::vector<tower> towers(3);
    Towers = &towers;
    init_hanoi(Height, towers[0]);
    std::cout << std::string(Height * 3 + 2*3, '=') << '\n';
    print_hanoi(Height, towers[0], towers[1], towers[2]);
    solve_hanoi(Height, towers[0], towers[1], towers[2]);

//    2
//    print_hanoi(2, {2,1}, {0,0}, {0,0});
//    print_hanoi(2, {2,0}, {1,0}, {0,0});  // ltm  // 1
//    print_hanoi(2, {0,0}, {1,0}, {2,0});  // ltr  // 2
//    print_hanoi(2, {0,0}, {0,0}, {2,1});  // mtr  // 3

//    3
//    print_hanoi(3, {3,2,1}, {0,0,0}, {0,0,0});
//    print_hanoi(3, {3,2,0}, {0,0,0}, {1,0,0});    // ltr
//    print_hanoi(3, {3,0,0}, {2,0,0}, {1,0,0});    // ltm
//    print_hanoi(3, {3,0,0}, {2,1,0}, {0,0,0});    // rtm
//    print_hanoi(3, {0,0,0}, {2,1,0}, {3,0,0});    // ltr
//    print_hanoi(3, {1,0,0}, {2,0,0}, {3,0,0});    // mtl
//    print_hanoi(3, {1,0,0}, {0,0,0}, {3,2,0});    // mtr
//    print_hanoi(3, {0,0,0}, {0,0,0}, {3,2,1});    // ltr

//    4
//    print_hanoi(4, {4,3,2,1}, {0,0,0,0}, {0,0,0,0});
//    print_hanoi(4, {4,3,2,0}, {1,0,0,0}, {0,0,0,0});  // ltm  // 1
//    print_hanoi(4, {4,3,0,0}, {1,0,0,0}, {2,0,0,0});  // ltr  // 2
//    print_hanoi(4, {4,3,0,0}, {0,0,0,0}, {2,1,0,0});  // mtr  // 3
//    print_hanoi(4, {4,0,0,0}, {3,0,0,0}, {2,1,0,0});  // ltm  // 4
//    print_hanoi(4, {4,1,0,0}, {3,0,0,0}, {2,0,0,0});  // rtl  // 5
//    print_hanoi(4, {4,1,0,0}, {3,2,0,0}, {0,0,0,0});  // rtm  // 6
//    print_hanoi(4, {4,0,0,0}, {3,2,1,0}, {0,0,0,0});  // ltm  // 7
//    print_hanoi(4, {0,0,0,0}, {3,2,1,0}, {4,0,0,0});  // ltr  // 8
//    print_hanoi(4, {0,0,0,0}, {3,2,0,0}, {4,1,0,0});  // mtr  // 9
//    print_hanoi(4, {2,0,0,0}, {3,0,0,0}, {4,1,0,0});  // mtl  // 10
//    print_hanoi(4, {2,1,0,0}, {3,0,0,0}, {4,0,0,0});  // rtl  // 11
//    print_hanoi(4, {2,1,0,0}, {0,0,0,0}, {4,3,0,0});  // mtr  // 12
//    print_hanoi(4, {2,0,0,0}, {1,0,0,0}, {4,3,0,0});  // ltm  // 13
//    print_hanoi(4, {0,0,0,0}, {1,0,0,0}, {4,3,2,0});  // ltr  // 14
//    print_hanoi(4, {0,0,0,0}, {0,0,0,0}, {4,3,2,1});  // mtr  // 15
    return 0;
}