#include <iostream>
#include <vector>
#include <algorithm>

#include <cassert>

template <typename It> // It - bidirectional iterator
bool next_permutation(It first, It last)
{
	// Code taken from cppreference - https://en.cppreference.com/w/cpp/algorithm/next_permutation
	// Explanation taken from geeksforgeeks - https://www.geeksforgeeks.org/lexicographically-next-permutation-in-cpp/

	// For step 1. we need a "reversed" sequence
	auto r_first = std::make_reverse_iterator(last);
	auto r_last = std::make_reverse_iterator(first);
	// 1. Traverse squence from the right and find the first element that
	//    is not following the descending order
	auto left = std::is_sorted_until(r_first, r_last);
	if(left != r_last){
		// find closest greater element to the element from step 1.
		auto right = std::upper_bound(r_first, left, *left);
		// 2. Swap element from 1. with the closest greater element
		std::iter_swap(left, right);
	}
	// 3. Reverse what left of the sequence
	std::reverse(left.base(), last);
	return left != r_last;
}

// 0 1 2 5 3 3 0
// 0 1 3 0 2 3 5
template <typename T>
std::vector<T> &next_permutation(std::vector<T> &seq)
{
	size_t size = seq.size();
	// 1) Find largest index I such that seq[I − 1] < seq[I]
	size_t I = 0;
	for (size_t i = size - 1; i > 0; --i)
	{
		if (seq[i] > seq[i - 1])
		{
			I = i;
			break;
		}
	}
	// If no such I exists, then this is already the last permutation
	if (I == 0)
	{
		return seq;
	}
	// 2) Find largest index J such that J ≥ I and seq[J] > seq[I − 1].
	size_t J = I - 1;
	for (size_t j = size - 1; j >= I; --j)
	{
		if (seq[j] > seq[I - 1])
		{
			J = j;
			break;
		}
	}
	// 3) Swap seq[J] and seq[J − 1].
	std::swap(seq[J], seq[I - 1]);
	// 4) Reverse seq[I..N]
	std::reverse(seq.begin() + I, seq.end());

	return seq;
}

template <typename T>
void print_vect(const std::vector<T> &v)
{
	for (const auto &el : v)
	{
		std::cout << el << ' ';
	}
	std::cout << '\n';
}

int main()
{
	if (true)
	{
		std::vector<int> v1 = {0, 1, 2, 5, 3, 3, 0};
		print_vect(v1);
		// next
		print_vect(next_permutation(v1)); // 0 1 2 5 3 3 0
		print_vect(next_permutation(v1)); // 0 1 3 0 2 5 3
		print_vect(next_permutation(v1)); // 0 1 3 0 3 2 5
		print_vect(next_permutation(v1)); // 0 1 3 0 3 5 2

		std::cout << '\n';

		// check yourself
		std::vector<int> v1c = {0, 1, 2, 5, 3, 3, 0};
		print_vect(v1c);
		std::next_permutation(v1c.begin(), v1c.end()); // 0 1 2 5 3 3 0
		print_vect(v1c);
		std::next_permutation(v1c.begin(), v1c.end()); // 0 1 3 0 2 5 3
		print_vect(v1c);
		std::next_permutation(v1c.begin(), v1c.end()); // 0 1 3 0 3 2 5
		print_vect(v1c);
		std::next_permutation(v1c.begin(), v1c.end()); // 0 1 3 0 3 5 2
		print_vect(v1c);

		std::cout << '\n';
	}

	if (true)
	{
		std::vector<int> v2 = {4, 2, 5, 3, 1};
		print_vect(v2);
		// next
		print_vect(next_permutation(v2));
		print_vect(next_permutation(v2));
		print_vect(next_permutation(v2));
		print_vect(next_permutation(v2));

		std::cout << '\n';
	}

	if (true)
	{
		std::vector<char> v3 = {'F', 'A', 'D', 'E'};
		print_vect(v3);
		// next
		print_vect(next_permutation(v3));
		print_vect(next_permutation(v3));
		print_vect(next_permutation(v3));

		v3 = {'F', 'A', 'D', 'E'};
		std::vector<char> v3c1 = {'F', 'A', 'D', 'E'};
		std::vector<char> v3c2 = {'F', 'A', 'D', 'E'};
		while (std::next_permutation(v3c1.begin(), v3c1.end())) {
			next_permutation(v3);
			::next_permutation(v3c2.begin(), v3c2.end());

			// DEBUG
			// print_vect(v3c1);
			// print_vect(v3c2);
			// std::cout << '\n';

			assert(v3c1 == v3c2);
			assert(v3c1 == v3);
		}

		std::cout << '\n';
	}

	return 0;
}