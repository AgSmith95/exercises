#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// s is a line representing positions in the chamber
// particles is a list of positions in s
// speed is positive for R and negative for L particles
void update_positions(std::string& s, std::vector<int>& particles, int speed) {
    if (particles.empty()) return;
    auto it = particles.begin();
    while (it != particles.end()) {
        bool erase = false;
        s[*it] = 'X';
        *it += speed;
        if (*it >= (int)s.size() || *it < 0) {
            erase = true;
        }
        if (erase) {
            it = particles.erase(it);
        }
        else {
            ++it;
        }
    }
}

std::vector<std::string> simulate_particles(const std::string& s, int speed) {
    std::vector<std::string> ret{};

    size_t size = s.size();
    if (size == 0) {
        ret.emplace_back("");
        return ret;
    }

    // < PARSE INPUT>
    std::vector<int> left_particles;
    std::vector<int> right_particles;
    for (size_t i = 0; i < size; ++i) {
        if (s[i] == 'R') right_particles.push_back((int)i);
        else if (s[i] == 'L') left_particles.push_back((int)i);
        else if (s[i] != '.') return ret;
    }
    // </PARSE INPUT>

    // < SIMULATE>
    if (speed != 0) {
        while (!left_particles.empty() || !right_particles.empty()) {
            // < CONSTRUCT A SIMULATION FRAME AND UPDATE POSITIONS>
            ret.emplace_back(size, '.');
            update_positions(ret.back(), right_particles, speed);
            update_positions(ret.back(), left_particles, -speed);
            // </CONSTRUCT A SIMULATION FRAME AND UPDATE POSITIONS>
        }
        ret.emplace_back(size, '.');
    }
    else { // corner case when speed is 0
        ret.emplace_back(size, '.');
        update_positions(ret.back(), right_particles, speed);
        update_positions(ret.back(), left_particles, -speed);
    }
    // </SIMULATE>

    return ret;
}

template<typename T>
void print_vec(const std::vector<T>& v) {
    for (const auto& e: v) {
        std::cout << e << '\n';
    }
    std::cout << '\n';
}

// RR..LRL 3
int main() {
    // trivial testcase
    std::vector<std::string> ref = {""};
    std::vector<std::string> res = simulate_particles("", 1);
    assert(ref == res);
    // speed = 0
    ref = {".X."};
    res = simulate_particles(".L.", 0);
    assert(ref == res);
    ref = {".X."};
    res = simulate_particles(".R.", 0);
    assert(ref == res);

    // testcase (e)
    ref = {"..."};
    res = simulate_particles("...", 1);
    assert(ref == res);
    // testcase (a)
    ref = {"..X.....", "....X...", "......X.", "........"}; // WRONG TESTCASE IN EXAMPLE
    res = simulate_particles("..R.....", 2);
    assert(ref == res);
    // testcase (b)
    ref = {"XX..XXX", ".X.XX..", "X.....X", "......."};
    res = simulate_particles("RR..LRL", 3);
    assert(ref == res);
    // testcase (c)
    ref = {"XXXX.XXXX", "X..X.X..X", ".X.X.X.X.", ".X.....X.", "........."}; // WRONG TESTCASE IN EXAMPLE
    res = simulate_particles("LRLR.LRLR", 2);
    assert(ref == res);
    // testcase (d)
    ref = {"XXXXXXXXXX", ".........."};
    res = simulate_particles("RLRLRLRLRL", 10);
    assert(ref == res);
    // testcase (f)
    ref = {
        "XXXX.XX.XXX.X.XXXX.",
        "..XXX..X..XX.X..XX.",
        ".X.XX.X.X..XX.XX.XX",
        "X.X.XX...X.XXXXX..X",
        ".X..XXX...X..XX.X..",
        "X..X..XX.X.XX.XX.X.",
        "..X....XX..XX..XX.X",
        ".X.....XXXX..X..XX.",
        "X.....X..XX...X..XX",
        ".....X..X.XX...X..X",
        "....X..X...XX...X..",
        "...X..X.....XX...X.",
        "..X..X.......XX...X",
        ".X..X.........XX...",
        "X..X...........XX..",
        "..X.............XX.",
        ".X...............XX",
        "X.................X",
        "..................."
    };
    res = simulate_particles("LRRL.LR.LRR.R.LRRL.", 1);
    assert(ref == res);

    return 0;
}