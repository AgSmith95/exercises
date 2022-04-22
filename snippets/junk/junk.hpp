#include <iostream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    out << "[ ";
    for(const auto &e: v) {
        out << e << ' ';
    }
    out << "]\n";

    return out;
}
