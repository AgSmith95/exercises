#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

int main() {
    std::vector<int> v{1,2,3,3,3,3,4,5,6,7};

    std::cout << "[ ";
    for (const auto& e: v) {
        std::cout << e << ' ';
    }
    std::cout << "]\n";

    v.erase(std::remove(v.begin(), v.end(), 3), v.end());

    std::cout << "[ ";
    for (const auto& e: v) {
        std::cout << e << ' ';
    }
    std::cout << "]\n";

    std::thread t([](){ std::cout << "\nfrom thread\n"; });
    t.join();

    return 0;
}