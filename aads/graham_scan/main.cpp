#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#include "convex_hull.h"

// https://en.wikipedia.org/wiki/Graham_scan
// https://web.archive.org/web/20180528104521/http://www.tcs.fudan.edu.cn/~rudolf/Courses/Algorithms/Alg_ss_07w/Webprojects/Qinbo_diameter/2d_alg.htm

// HELPERS
template<typename It>
using vtype = typename std::iterator_traits<It>::value_type;

template<typename It>
void print_vec(It first, It last) {
    std::cout << "{ ";
    for (first; first != last; ++first) {
        std::cout   << '[' << std::setprecision(2) << first->first
                    << ',' << std::setprecision(2) << first->second
                    << "] ";
    }
    std::cout << "}\n";
}
//template<typename It>
//void print_vec_op(It first, It last, vtype<It> x, double (*op)(double, double)) {
//    std::cout << "operation: { ";
//    for (; first != last; ++first) {
//        std::cout << op(x->first - first)
//    }
//    std::cout << "}\n";
//}

template<typename T>
void print_vec(const std::vector<T>& v) {
    std::cout << "{ ";
    for(const auto& e: v) {
        std::cout << e << " ";
    }
    std::cout << "}\n";
}

double cos_ox(double x, double y) {
    //if (x == 0.0 && y == 0.0) return -1.0;
    return x / sqrt(x*x + y*y);
}

double cross_product_z(std::pair<double, double> p1,
                       std::pair<double, double> p2,
                       std::pair<double, double> p3) {
    return  (p2.first - p1.first) * (p3.second - p1.second) -
            (p2.second - p1.second) * (p3.first - p1.first);
}
// HELPERS


// ======= Graham scan =======

template<typename It>
std::vector<vtype<It>> graham_scan(It first, It last) {
    // 0. do not pass less than 3 elements
    //    exactly 3 elements is either convex hull or a line so return too
    if (last - first <= 3) {
        return {first, last};
    }
    // 1. find point with min Y (if multiple - leftmost of that)
    double y = first->first;
    double x = first->second;
    for (auto it = first; it != last; ++it) {
        if (y > it->second) {
            y = it->second;
            x = it->first;
        }
        if (y == it->second && x > it->first) {
            x = it->first;
        }
    }
    std::cout << "[ " << x << ", " << y << " ]\n";

    // 2. sort elements in increasing order by the angle (1.) point
    //    and the current point makes with the X-axis
    std::sort(first, last, [x,y](const vtype<It>& p1, const vtype<It>& p2) -> bool {
//        return  atan2(y - p1.second, x - p1.first) >
//                atan2(y - p2.second, x - p2.first);
        return cos_ox(x - p1.first, y - p1.second) >
               cos_ox(x - p2.first, y - p2.second);
    });
    //return {first, last};

    // 3. check for right/left turn
    std::vector<vtype<It>> stack;
    for (auto it = first; it != last; ++it) {
        while (stack.size() > 1 && cross_product_z(*(stack.end() - 1), *(stack.end() - 2), *it) < 0) {
            stack.pop_back();
        }
        stack.emplace_back(*it);
    }

    return std::move(stack);
}
// ======= Graham scan =======

int main() {
//    std::vector<std::pair<double, double>> v1 = {{1, 1}, {1, 5}, {2, 4}, {4, 3}, {5, 5}, {5, 1}, {3, 2}};
//    std::vector<std::pair<double, double>> v2= {{1,4}, {2,4}, {4,5}, {4,6}, {4,3},
//                                                {6,3}, {3,3}, {3,1}, {3,2}};
//    auto ch1 = graham_scan(v1.begin(), v1.end());
//    print_vec(ch1.begin(), ch1.end());
//    std::cout << '\n';
//    std::cout << '\n';
//
//    auto ch2 = graham_scan(v2.begin(), v2.end());
//    print_vec(ch2.begin(), ch2.end());
//    std::cout << '\n';
//    std::cout << '\n';

    std::vector<pt> vv1 = {{1, 1}, {1, 5}, {2, 4}, {4, 3}, {5, 5}, {5, 1}, {3, 2}};
    std::vector<pt> vv2= {{1,4}, {2,4}, {4,5}, {4,6}, {4,3},
                         {6,3}, {3,3}, {3,1}, {3,2}};
    convex_hull(vv1);
    convex_hull(vv2);
    std::cout << "{ ";
    for (const auto& e: vv1) {
        printf("[%.0f, %.0f] ", e.x, e.y);
    }
    std::cout << "}\n";
    std::cout << "{ ";
    for (const auto& e: vv2) {
        printf("[%.0f, %.0f] ", e.x, e.y);
    }
    std::cout << "}\n";

    return 0;
}