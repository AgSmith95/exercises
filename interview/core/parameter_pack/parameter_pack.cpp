#include <iostream>

// [2] typename|class ... pack-name(optional)
template <typename... Types>
int sum_to_int(Types... args)
{
	return (int)(args + ...); // fold expression used here
}

// [1] type ... pack-name(optional)
// see also: https://en.cppreference.com/w/cpp/utility/integer_sequence
template <int... Ints>
int sum_ints_statically()
{
	return sum_to_int(Ints...);
}

// I know nothing about other types of paramter packs.
// TASK:
// Find more info on [3], [4], [5] and [6]

int main()
{
	// sum_to_int(int, float, char)
	std::cout << sum_to_int(5, 3.8f, 'a') << '\n'; // 105 // (int)(5 + 3.8 + 97)
	std::cout << sum_ints_statically<1,2,3,4,5>() << '\n'; // 15 // 1 + 2 + 3 + 4 + 5

	return 0;
}
