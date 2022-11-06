#include <iostream>

// [2] typename|class ... pack-name(optional)
template <typename... Types>
int sum_to_int(Types... args)
{
	return (int)(args + ...); // fold expression used here
}

// I know nothing about other types of paramter packs.
// TASK:
// Find more info on [1], [3], [4], [5] and [6]

int main()
{
	// sum_to_int(int, float, char)
	std::cout << sum_to_int(5, 3.8f, 'a') << '\n'; // 105 // (int)(5 + 3.8 + 97)

	return 0;
}
