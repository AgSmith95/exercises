#include <iostream>
#include <vector>
#include <algorithm>

// 0 1 2 5 3 3 0
// 0 1 3 0 2 3 5
template <typename T>
std::vector<T>& next_permutation(std::vector<T>& seq) {
    size_t size = seq.size();
    // 1) Find largest index I such that seq[I − 1] < seq[I]
    size_t I = 0;
    for (size_t i = size - 1; i > 0; --i) {
        if (seq[i] > seq[i-1]) {
            I = i;
            break;
        }
    }
    // If no such I exists, then this is already the last permutation
    if (I == 0) {
        return seq;
    }
    // 2) Find largest index J such that J ≥ I and seq[J] > seq[I − 1].
    size_t J = I-1;
    for (size_t j = size - 1; j >= I; --j) {
        if (seq[j] > seq[I-1]) {
            J = j;
            break;
        }
    }
    // 3) Swap seq[J] and seq[J − 1].
    std::swap(seq[J], seq[I-1]);
    // 4) Reverse seq[I..N]
    std::reverse(seq.begin()+I, seq.end());

    return seq;
}

template <typename T>
void print_vect(const std::vector<T>& v) {
    for (const auto& el : v) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> v = {0, 1, 2, 5, 3, 3, 0};
    print_vect(v);
    // next
    print_vect(next_permutation(v));
    print_vect(next_permutation(v));
    print_vect(next_permutation(v));
    print_vect(next_permutation(v));

    std::cout << '\n';

    std::vector<int> v2 = {4, 2, 5, 3, 1};
    print_vect(v2);
    // next
    print_vect(next_permutation(v2));
    print_vect(next_permutation(v2));
    print_vect(next_permutation(v2));
    print_vect(next_permutation(v2));

    std::cout << '\n';

    std::vector<char> v3 = {'F', 'A', 'D', 'E'};
    print_vect(v3);
    // next
    print_vect(next_permutation(v3));
    print_vect(next_permutation(v3));
    print_vect(next_permutation(v3));
    return 0;
}