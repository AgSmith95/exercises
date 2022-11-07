#include <iostream>
#include <concepts> // for type [3]

// for type [3]
template<typename T>
concept Number = std::is_integral<T>::value || std::is_floating_point<T>::value;

// [2] typename|class ... pack-name(optional)
template <typename... Types>
auto sum(const Types&... args)
{
	return (args + ...); // fold expression used here
}

// [1] type ... pack-name(optional)
// see also: https://en.cppreference.com/w/cpp/utility/integer_sequence
template <int... Ints>
int sum_ints_statically()
{
	return sum(Ints...);
}

// I know nothing about other types of paramter packs.
// TASK:
// Find more info on [3], [4], [5] and [6]

int main()
{
	// sum(int, float, char)
	std::cout << sum(5, 3.8f, 'a') << '\n'; // 105.8 // 5 + 3.8 + 97
	std::cout << sum_ints_statically<1,2,3,4,5>() << '\n'; // 15 // 1 + 2 + 3 + 4 + 5

	return 0;
}
