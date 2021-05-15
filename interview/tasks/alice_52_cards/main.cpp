#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

long add(long a, long b) {
    return a + b;
}
long sub(long a, long b) {
    return a - b;
}
long mul(long a, long b) {
    return a * b;
}

const vector<function<long(long,long)>> ops = {add, sub, mul};
const char signs[3] = {'+', '-', '*'};

bool can_reach_42(vector<int>& v, bool debug = false) {
    if (v.size() != 5) {
        throw 1;
    }

    sort(v.begin(), v.end());
    do {
        for (auto i = 0; i < 3; ++i) {
            for (auto j = 0; j < 3; ++j) {
                for (auto k = 0; k < 3; ++k) {
                    for (auto l = 0; l < 3; ++l) {
                        long res = ops[i](v[0], v[1]);
                        res = ops[j](res, v[2]);
                        res = ops[k](res, v[3]);
                        res = ops[l](res, v[4]);
                        if (res == 42) {
                            if (debug) {
                                cout << "Expr: " << v[0] << ' ' << signs[i] << ' ' <<
                                                    v[1] << ' ' << signs[j] << ' ' <<
                                                    v[2] << ' ' << signs[k] << ' ' <<
                                                    v[3] << ' ' << signs[l] << ' ' <<
                                                    v[4] << '\n';
                            }
                            return true;
                        }
                    }
                }
            }
        }
    } while (next_permutation(v.begin(), v.end()));

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
        if (can_reach_42(v, true)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
