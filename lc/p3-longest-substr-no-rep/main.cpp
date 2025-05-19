#include <iostream>
#include <cstdint>
#include <cstring>

using std::string;

class Solution {
	int positions[128];
public:
	int lengthOfLongestSubstring(const string& s) {
		const int len = s.length();
		if (len < 2) return len;

		int res = 0;
		for (int i = 0; i < len; ++i) {
			std::memset(positions, -1, sizeof positions);
			int curr_max = 0;
			for (int j = i; j < len; ++j) {
				const char sj = s[j]; // DEBUG
				int& pos_sj = positions[(int)sj];
				if (pos_sj >= i) {
					i = pos_sj; // +1 will be handled by the outer for loop
					break;
				}
				pos_sj = j;
				++curr_max;
			}
			res = res < curr_max ? curr_max : res;
		}

		return res;
	}
};

int main() {
	Solution sol;
	string s;
	int res = 0;

	// s = "";	// 0
	// res = sol.lengthOfLongestSubstring(s);
	// std::cout << "res('" << s << "') = " << res << '\n';
	// s = "x";	// 1
	// res = sol.lengthOfLongestSubstring(s);
	// std::cout << "res('" << s << "') = " << res << '\n';

	s = "bbbbb";	// 1
	res = sol.lengthOfLongestSubstring(s);
	std::cout << "res('" << s << "') = " << res << '\n';

	s = "abcabcbb";	// 3
	res = sol.lengthOfLongestSubstring(s);
	std::cout << "res('" << s << "') = " << res << '\n';

	s = "pwwkew";	// 3
	res = sol.lengthOfLongestSubstring(s);
	std::cout << "res('" << s << "') = " << res << '\n';

	s = "abcabcdefbb";	// 6
	res = sol.lengthOfLongestSubstring(s);
	std::cout << "res('" << s << "') = " << res << '\n';

	s = "au";	// 2
	res = sol.lengthOfLongestSubstring(s);
	std::cout << "res('" << s << "') = " << res << '\n';

	s = "auab";	// 4
	res = sol.lengthOfLongestSubstring(s);
	std::cout << "res('" << s << "') = " << res << '\n';

	return 0;
}