#include "one.h"
#include <algorithm>
#include <stack>

/**
 * There is a city map M*N blocks
 *
 * 0 - don't care
 * 1 - real shit
 *
 * Map from example looked like:
 * 1 1 0 0
 * 0 0 1 0
 * 0 0 0 0
 * 1 0 1 1
 * 1 1 1 1
 *
 * Needed to count all "contiguous" areas of 1s
 * Diagonals don't count
 *
 * In the example we have 3:
 * 1 1
 *     1
 *
 * 1   1 1
 * 1 1 1 1
 */

positions adjacent(const gridvec& grid, const pos& p) {
    positions ret;
    size_t x = p.first;
    size_t y = p.second;
    if (y < (grid[x].size() - 1) && grid[x][y+1]) {
        ret.push_back({x, y + 1});
    }
    if (y > 0 && grid[x][y-1] == 1) {
        ret.push_back({x, y - 1});
    }
    if (x < (grid.size() - 1) && grid[x+1][y] == 1) {
        ret.push_back({x + 1, y});
    }
    if (x > 0 && grid[x-1][y] == 1) {
        ret.push_back({x - 1, y});
    }
    return ret;
}

bool is_discovered(const pos& p, const positions& discovered) {
    return std::find(discovered.begin(), discovered.end(), p) != discovered.end();
}

int numAdjacent(const gridvec& grid, const pos& p, positions& discovered) {
    int ret = 0;
    std::stack<pos> s;
    s.push(p);
    while (!s.empty()) {
        auto v = s.top();
        s.pop();
        if (!is_discovered(v, discovered)) {
            discovered.push_back(v);
            ++ret;
            for(auto& el: adjacent(grid, v)) {
                s.push(el);
            }
        }
    }
    return ret;
}

int numTruck(const gridvec& grid) {
    int res = 0;
    positions discovered;
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 1 && numAdjacent(grid, {i,j}, discovered) != 0) {
                ++res;
            }
        }
    }
    return res;
}
