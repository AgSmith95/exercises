#ifndef PROJECT_ONE_H
#define PROJECT_ONE_H

#include <vector>

using std::vector;
using pos = std::pair<size_t ,size_t>;
using positions = vector<pos>;
using gridvec = vector<vector<int>>;

positions adjacent(const gridvec& grid, const pos& p);
bool is_discovered(const pos& p, const positions& discovered);
int numAdjacent(const gridvec& grid, const pos& p, positions& discovered);
int numTruck(const gridvec& grid);

#endif //PROJECT_ONE_H
