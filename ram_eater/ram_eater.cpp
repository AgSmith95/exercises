#include <iostream>
#include <cstdlib>
#include <cstring>

struct mega {
    char meg[1024*1024];
    mega(): meg{} {
        //memset(meg, 0 , sizeof(meg)); // isn't necessary
    };
};

int main(int argc, char** args) {
    if (argc < 2) {
        std::cout << "usage: ./ram_eater X; where X - number of megabytes to eat\n";
        return 1;
    }
    long megs = std::strtol(args[1], nullptr, 10);
    mega *m = nullptr;
    if (megs > 0) {
        m = new mega[megs];
        std::cout << "Input something to continue: ";
        std::cin >> m[0].meg;
        delete[] m;
    }
    return 0;
}