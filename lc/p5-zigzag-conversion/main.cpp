#include <iostream>
#include <cstring>
#include <vector>

using std::string;

class Solution {
public:
	string convert(const string& s, const int numRows) {
		int len = s.length();
		if (len < numRows) return s;

		std::vector<string> strArr(numRows); // create array for a result
		int diagLen = numRows - 2;
		int down = 0, diag = 0;
		// compute the result
		for (int i = 0; i < len; ++i) {
			if (down < numRows) {
				strArr[down % numRows].push_back(s[i]);
				++down;
				continue;
			}
			else if (diag < diagLen) {
				strArr[numRows - diag - 2].push_back(s[i]);
				++diag;
				continue;
			}
			down = diag = 0;
			--i;
		}

		// concatenate everythig to strArr[0]
		for (int i = 1; i < numRows; ++i) {
			strArr[0].append(strArr[i]);
		}
		return strArr[0];
	}
};

int main() {
	Solution sol;

	{
		string s = "PAYPALISHIRING";
		int numRows = 3;
		std::cout	<< "  s='" << s << "' numRows=" << numRows << '\n'
					<< "res='" << sol.convert(s, numRows) << "'\n\n";
	}

	{
		string s = "PAYPALISHIRING";
		int numRows = 4;
		std::cout	<< "  s='" << s << "' numRows=" << numRows << '\n'
					<< "res='" << sol.convert(s, numRows) << "'\n\n";
	}

	{
		string s = "A";
		int numRows = 1;
		std::cout	<< "  s='" << s << "' numRows=" << numRows << '\n'
					<< "res='" << sol.convert(s, numRows) << "'\n\n";
	}

	{
		string s = "ABCDE";
		int numRows = 8;
		std::cout	<< "  s='" << s << "' numRows=" << numRows << '\n'
					<< "res='" << sol.convert(s, numRows) << "'\n\n";
	}

	return 0;
}