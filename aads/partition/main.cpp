#include <algorithm>
#include <iostream>
#include <vector>

#include <cassert>

template <typename It, typename Condition>
// It - forward iterator
It partition(It first, It last, Condition cond) {
	// Code taken from cppreference - https://en.cppreference.com/w/cpp/algorithm/partition

	// skip all elements that satisfy the condition
	// finding a first one that doesn't satisfy it in the process
	first = std::find_if_not(first, last, cond);
	if (first == last) return first;

	// starting from the next element see
	for (It i = std::next(first); i != last; ++i) {
		// if cond applies
		if (cond(*i)) {
			// swap it with the first element to which
			// cond didn't apply in the past
			std::iter_swap(i, first);
			// and shift the "boundary" of the partition
			++first;
		}
	}
	return first;
}

template <typename It>
void print(It first, It last) {
	std::cout << "[ ";
	for (; first != last; ++first) {
		std::cout << *first << ' ';
	}
	std::cout << "]\n";
}

int main() {
	if (true) {
		std::vector<int> vi = {5, 3, 7, 1, 10, 2, 6, 4, 8, 9};
		print(vi.begin(), vi.end()); // [ 5 3 7 1 10 2 6 4 8 9 ]
		auto my_res = ::partition(vi.begin(), vi.end(), [](int x) { return x <= 5; });
		print(vi.begin(), vi.end()); // [ 5 3 1 2 4 7 6 10 8 9 ]

		std::vector<int> vic = {5, 3, 7, 1, 10, 2, 6, 4, 8, 9};
		auto std_res = std::partition(vic.begin(), vic.end(), [](int x) { return x <= 5; });
		print(vic.begin(), vic.end()); // [ 5 3 4 1 2 10 6 7 8 9 ]

		// partitioning happens, BUT
		// the results are different
		assert(std::distance(vi.begin(), my_res) == std::distance(vic.begin(), std_res));
		// partition is at the same point
	}

	return 0;
}