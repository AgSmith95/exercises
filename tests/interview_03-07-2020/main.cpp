/**
 * no compiler/debugger/web
 *
 * std::vector<T>
 * T is less comparable
 * vector sorted by less operator of T
 *
 * vector parameters:
 * 1st part go down
 * 2nd part - up
 *
 * in between there is a minimum
 *
 * job is to find the minimum
 *
 * dont waste time/memory
 * write as simple and as elegant as possible
 */

// sort of:
// bool operator<(const T& l, const T& r) { return l < r; }
// 5 < 8    true
// !(5 < 8) == 5 >= 8   false
// 3 < 3 false; !(3 < 3) true;

// examples:
// 10 5 1 5 10
// 10 3 1 5 7
// 10 9 8 7 6 5 4 3 3 3 4 5 6 7 8
// 10 7 5 3 3 9 9 9 11
// 10 7 5 5 5 3 3 9 9 9 11
// the worst case I can think of:
// 12 10 7 5 5 5 3 3 3 5 5 5 10 11 13
// 5 5 5 3 3 3 5 5 5

#include <vector>

template <typename T>
bool less_or_equal(const T& l, const T& r) {
    if (l < r) {
        return true;
    }
    return !(r < l);
}

template <typename T>
T find_min(const std::vector<T>& v) {
    size_t i = v.size() - 1;
    while ( (i != 0) && less_or_equal(v[i - 1], v[i]) ) {
        --i;
    }
    return v[i];
}

template <typename T>
T find_min_log_n(const std::vector<T>& v) {
    auto beg = v.begin();
    auto end = v.end() - 1;
    decltype(beg) mid;
    while ((end - beg) > 1) {
        mid = beg + (end - beg) / 2;
        if (*(mid - 1) < *mid) {
            end = mid - 1;
        }
        else {
            beg = mid;
        }
    }
    if (*beg < *end) {
        return *beg;
    }
    return *end;
}

template <typename T>
bool equal(const T& l, const T& r) {
    return !(l < r) && !(r < l);
}

template <typename T>
T find_min_log_n_with_duplicates(const std::vector<T>& v) {
    auto beg = v.begin();
    auto end = v.end() - 1;
    decltype(beg) mid;
    while ((end - beg) > 1) {
        mid = beg + (end - beg) / 2;
        if (*(mid - 1) < *mid) {
            end = mid - 1;
        }
        else if (!equal(*mid, *(mid - 1))) {
            beg = mid;
        }
        else {
            // mid and mid-1 are equal - totally messed up case, tbh
            // have to find borders of an interval with equal values
            decltype(beg) lborder = mid;
            decltype(beg) rborder = mid;
            // this thing is now, basically, reduced to O(N). Too bad
            while (((lborder - beg) > 0) && equal(*(lborder-1), *lborder)) {
                --lborder;
            }
            while (((end - rborder) > 0) && equal(*rborder, *(rborder+1))) {
                ++rborder;
            }
            // analysis time
            if (lborder == beg) {
                beg = rborder;
            }
            else if (rborder == end) {
                end = lborder;
            }
            else if (*lborder < *(lborder-1)) {
                beg = rborder;
            }
            else {
                end = lborder;
            }
        }
    }
    if (*beg < *end) {
        return *beg;
    }
    return *end;
}

template <typename T>
T find_min_log_n_with_duplicates_new(const std::vector<T>& v) {
    auto beg = v.begin();
    auto end = v.end() - 1;
    decltype(beg) mid;
    while ((end - beg) > 1) {
        mid = beg + (end - beg) / 2;
        if (*(mid - 1) < *mid) {
            end = mid - 1;
        }
        else if (!equal(*mid, *(mid - 1))) {
            beg = mid;
        }
        else {
            // mid and mid-1 are equal - totally messed up case, tbh
            // have to find borders of an interval with equal values
            decltype(beg) lborder = mid;
            decltype(beg) rborder = mid;
            // this thing is now, basically, reduced to O(N). Too bad
            while (((lborder - beg) > 0) && equal(*(lborder-1), *lborder)) {
                --lborder;
            }
            while (((end - rborder) > 0) && equal(*rborder, *(rborder+1))) {
                ++rborder;
            }
            // analysis time
            if (((lborder == beg) && (rborder != end)) || (*lborder < *(lborder-1))) {
                beg = rborder;
            }
            else {
                end = lborder;
            }
        }
    }
    if (*beg < *end) {
        return *beg;
    }
    return *end;
}

#include <iostream>
#include <fstream>
#include "helpers.hpp"
#include <cmath>
#include <chrono>

int main() {
    // LINEAR
    {
        std::cout << "\n======== LINEAR ========\n";
        std::cout << find_min<int>({5, 4, 3, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5}) << ' ';
        std::cout << find_min<int>({5, 4, 3, 2, 1, 6, 7, 8, 9}) << ' ';
        std::cout << find_min<int>({10, 9, 8, 7}) << ' ';
        std::cout << find_min<int>({10, 9, 8, 7, 8, 9}) << ' ';
        std::cout << find_min<int>({10, 9, 8, 7, 7, 7, 8, 9}) << ' ';
        std::cout << find_min<int>({5, 5, 5, 3, 3, 3, 5, 5, 5}) << ' ';
        std::cout << find_min<int>({1, 2, 3}) << ' ';
        std::cout << find_min<int>({99}) << ' ';
        std::cout << find_min<int>({99, 98}) << ' ';
        std::cout << find_min<int>(
                {-10, -11, -12, -13, -13, -13, -15, -15, -15, -13, -13, -13, -10, -5, -3}) << ' ';
    }
    // LOG
    {
        std::cout << "\n======== LOG ========\n";
        std::cout << find_min_log_n<int>({5, 4, 3, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5}) << ' ';
        std::cout << find_min_log_n<int>({5, 4, 3, 2, 1, 6, 7, 8, 9}) << ' ';
        std::cout << find_min_log_n<int>({10, 9, 8, 7}) << ' ';
        std::cout << find_min_log_n<int>({10, 9, 8, 7, 8, 9}) << ' ';
        std::cout << find_min_log_n<int>({10, 9, 8, 7, 7, 7, 8, 9}) << ' ';
        std::cout << find_min_log_n<int>({5, 5, 5, 3, 3, 3, 5, 5, 5}) << ' ';
        std::cout << find_min_log_n<int>({1, 2, 3}) << ' ';
        std::cout << find_min_log_n<int>({99}) << ' ';
        std::cout << find_min_log_n<int>({99, 98}) << ' ';
        std::cout << find_min_log_n<int>(
                {-10, -11, -12, -13, -13, -13, -15, -15, -15, -13, -13, -13, -10, -5, -3}) << ' ';
    }
    // LOG WITH DUPLICATES
    {
        std::cout << "\n======== LOG WITH DUPLICATES ========\n";
        std::cout << find_min_log_n_with_duplicates<int>(
                {5, 4, 3, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 3, 4, 5}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({5, 4, 3, 2, 1, 6, 7, 8, 9}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({10, 9, 8, 7}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({10, 9, 8, 7, 8, 9}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({10, 9, 8, 7, 7, 7, 8, 9}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({5, 5, 5, 3, 3, 3, 5, 5, 5}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({1, 2, 3}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({99}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>({99, 98}) << ' ';
        std::cout << find_min_log_n_with_duplicates<int>(
                {-10, -11, -12, -13, -13, -13, -15, -15, -15, -13, -13, -13, -10, -5, -3}) << ' ';
        std::cout << "\nOTHERS: ";
        // 140
        std::cout << find_min_log_n_with_duplicates<int>(
                {209, 209, 209, 209, 209, 209, 140, 140, 140, 184, 184, 184, 184, 184, 268, 268,
                 268,
                 268, 268, 268}) << ' ';
        // -458
        std::cout << find_min_log_n_with_duplicates<int>(
                {-458, -458, -458, -458, -458, -458, -444, -405, -405, -405, -405, -405, -405, -405,
                 -405, -405, -405, -405, -405, -311, -311, -311}) << ' ';
        // 785
        std::cout << find_min_log_n_with_duplicates<int>({785, 785, 785, 785, 785, 785}) << ' ';
    }
    // HELPERS TEST
    {
        std::cout << "\n======== HELPERS TEST ========\n";
        writeToOut(generate(20, 5));
        writeToOut(generate(20, 5));
        writeToOut(generate(20, 5));
        writeToOut(generate(20, 5));
        writeToOut(generate(5, 20));
        writeToOut(generate(5, 20));
        writeToOut(generate(5, 20));
        writeToOut(generate(5, 20));
    }
    std::cout << "\n======== RANDOMIZED TEST ========\n";
    size_t size;
    size_t pos;
    size_t err_count = 0;
    std::ofstream output_file;
    output_file.open("output.txt");

    for (size_t j = 0; j < 100; ++j) {
        std::chrono::high_resolution_clock::time_point beg; // for benchmarking
        std::chrono::high_resolution_clock::time_point end; // for benchmarking
        std::chrono::microseconds elapsed1{0}; // for benchmarking
        std::chrono::microseconds elapsed2{0}; // for benchmarking

        for (size_t i = 0; i < 90000; ++i) {
            size = abs(distrib(gen));
            pos = abs(distrib(gen));
            if (size < pos) {
                std::swap(size, pos);
            }
            if (pos == size) {
                --pos;
            }
            auto v = generate(size, pos);

            // no-squeezing solution
            beg = std::chrono::high_resolution_clock::now(); // for benchmarking
            auto result1 = find_min_log_n_with_duplicates(v);
            end = std::chrono::high_resolution_clock::now(); // for benchmarking
            elapsed1 += std::chrono::duration_cast<std::chrono::microseconds>(
                    end - beg); // for benchmarking
            if (result1 != v[pos]) {
                ++err_count;
                std::cout << "ERROR " << err_count << '\n';
                output_file << result1 << " != " << "v[" << pos << "] = " << v[pos] << " | size = "
                            << size << " | v : [";
                writeToOut(v, output_file);
                output_file << "]\n";
            }

            // "squeezing" solution
            beg = std::chrono::high_resolution_clock::now(); // for benchmarking
            auto result2 = find_min_log_n_with_duplicates_new(v);
            end = std::chrono::high_resolution_clock::now(); // for benchmarking
            elapsed2 += std::chrono::duration_cast<std::chrono::microseconds>(
                    end - beg); // for benchmarking
            if (result2 != v[pos]) {
                ++err_count;
                std::cout << "ERROR " << err_count << '\n';
                output_file << result2 << " != " << "v[" << pos << "] = " << v[pos] << " | size = "
                            << size << " | v : [";
                writeToOut(v, output_file);
                output_file << "]\n";
            }

            // progress bar... sort of
//        if (i % 10000 == 0) {
//            std::cout << (i / 10000) << '\n';
//        }
//        if (i % 100 == 0) {
//            std::cout << '.';
//        }
        }
        std::cout << '\n';
        std::cout << j << ": \t"
                  << elapsed2.count() << "\t"
                  << elapsed1.count() << "\t"
                  << (elapsed2 - elapsed1).count(); // for benchmarking

    }

    std::cout << '\n';
    return 0;
}
