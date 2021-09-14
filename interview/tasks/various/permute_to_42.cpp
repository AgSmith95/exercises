#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <functional>

/**
 * Test if you can make number 42 of the given array of integers
 *   by placing various operations in between (return YES/NO):
 *
 * 2 * 4 * 5 - 1 + 3 = 42   YES
 * 2 * 4 * 5 + 3 - 1 = 42   YES
 * 2 * 5 * 4 + 3 - 1 = 42   YES
 * 2 * 5 * 4 - 1 + 3 = 42   YES
 *
 * 52 51 50 49 48           NO
 */

using namespace std;

long add(int a, int b) {
    return a + b;
}
long sub(int a, int b) {
    return a - b;
}
long mul(int a, int b) {
    return a * b;
}
vector<function<long(int, int)>> ops = {add, sub, mul};

bool test(vector<int>& v) {
    if (v.size() != 5) {
        throw 1;
    }
    sort(v.begin(), v.end());
    do {
        long res = 0;
        for (auto& op1: ops) {
            for (auto& op2: ops) {
                for (auto& op3: ops) {
                    for (auto& op4: ops) {
                        res = op1(v[0], v[1]);
                        res = op2(res, v[2]);
                        res = op3(res, v[3]);
                        res = op4(res, v[4]);
                        if (res == 42) {
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
    string num;
    vector<int> v;
    while (getline(cin, line)) {
        stringstream ss(line);
        while (getline(ss, num, ' ')) {
            v.push_back(stoi(num));
            //cout << v.back() << '\n';
        }

        if (test(v)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}