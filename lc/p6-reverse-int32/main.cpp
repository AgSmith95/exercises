#include <iostream>
#include <limits.h>
#include <cmath>

constexpr int MAX_DIV_10 = INT_MAX / 10;

class Solution {
public:
	int reverse(int x) {
		int sign = x > 0 ? 1 : -1;
		int res = 0;
		int x_last_digit = 0;
		while (x != 0) {
			if (res > MAX_DIV_10) return 0;
			res *= 10;
			x_last_digit = std::abs(x % 10);
			if (res > INT_MAX - x_last_digit) return 0;
			res += x_last_digit;
			x /= 10;
		}

		return res * sign;
	}
};

int main(int /*argc*/, char** /* argv*/) {
	Solution sol;

	{
		int   x = 123;
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
					<< res << "\n\n";
	}

	{
		int   x = -123;
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
					<< res << "\n\n";
	}

	{
		int   x = 1200000;
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
					<< res << "\n\n";
	}

	{
		int   x = 1'212'121'219;
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
		<< res << "\n\n";
	}

	{
		int   x = -1'212'121'212;
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
					<< res << "\n\n";
	}

	{
		int   x = 2'147'483'647; // INT_MAX - 2147483647
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
					<< res << "\n\n";
	}

	{
		int   x = 1463847412; // 1[INT_MAX/10 reversed] - max positive you can reverse to not trigger overflow
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
					<< res << "\n\n";
	}

	{
		int   x = -2147483648; // INT_MIN
		int res = sol.reverse(x);
		std::cout	<< "reverse(" << x << ")="
					<< res << "\n\n";
	}
	
	return 0;
}
