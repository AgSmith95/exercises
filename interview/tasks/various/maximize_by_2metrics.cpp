#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/**
 * Input:
 *  1st line: L N
 *      L - weight limit
 *      N - number of items
 *  N lines: P W
 *      P - item price
 *      W - item weight
 *
 *  Task:   maximize sum(Prices) while
 *          keeping sum(Weights) <= L;
 *
 *          return max(sum(Prices))
 *
 * Example:
 *   15 5 // L N
 *
 *     8 3
 *     5 5
 *     9 8
 *     3 5
 *     5 8
 *
 * Return: 17
 */

using namespace std;

int maximize(const vector<int>& prices, const vector<int>& weights, int L) {
    if (prices.size() != weights.size()) {
        throw 1;
    }

    int max = 0;
    for(auto i = 0; i < prices.size(); ++i) {
        int sum = prices[i];
        int weight = weights[i];

        for(auto j = 0; j < prices.size(); ++j) {
            if ((i != j) && ((weight + weights[j]) <= L)) {
                sum += prices[j];
                weight += weights[j];
            }
        }

        if (sum > max) {
            max = sum;
        }
    }

    return max;
}

int main() {
    string line;
    string num;
    int L = 0;
    int N = 0;
    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        getline(ss, num, ' ');
        L = stoi(num); // input L
        getline(ss, num, ' ');
        N = stoi(num); // input N

        vector<int> prices(N);
        vector<int> weights(N);
        for (auto i = 0; i < N; ++i) {
            getline(cin, line);
            // get price from line
            stringstream SS(line);
            getline(SS, num, ' ');
            prices[i] = stoi(num);
            // get weight from line
            getline(SS, num, ' ');
            weights[i] = stoi(num);
        }
        std::cout << maximize(prices, weights, L) << '\n';
    }

}