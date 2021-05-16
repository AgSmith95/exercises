#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template<typename It>
bool has_solution(It first0, It last0, typename std::iterator_traits<It>::value_type n) {
    if (first0 == last0) {
        return false;
    }
    if ((last0 - first0) == 1) {
        return n == *first0;
    }

    auto first = first0;
    while (first0 != last0) {
        std::swap(*first0, *first);
        if (has_solution(first + 1, last0, n - *first) ||
            has_solution(first + 1, last0, n + *first) ||
            (*first != 0 && n % *first == 0 && has_solution(first + 1, last0, n / *first))) {
            std::swap(*first0, *first);
            return true;
        }
        std::swap(*first0, *first);
        ++first0;
    }
    return false;
}

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> v;
        while (getline(ss, line, ' ')) {
            v.push_back(stoi(line));
        }
        if (has_solution(v.begin(), v.end(), 42)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}