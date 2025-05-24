#include <iostream>
#include <vector>

using std::vector;

class Solution {
	public:
	double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
		int n = a.size(), m = b.size();

		if (n > m) return findMedianSortedArrays(b, a);

		int lo = 0, hi = n;
		while (lo <= hi) {
			int ma = (lo + hi) / 2;			// partition of a[]
			int mb = (n + m + 1) / 2 - ma;	// partition of b[]

			// elements in a[] to the left and right of ma
			int aL = (ma == 0 ? INT_MIN : a[ma - 1]);
			int aR = (ma == n ? INT_MAX : a[ma]);

			// elements in b[] to the left and right of mb
			int bL = (mb == 0 ? INT_MIN : b[mb - 1]);
			int bR = (mb == m ? INT_MAX : b[mb]);

			// if valid partition - return the result
			if (aL <= bR && bL <= aR) {
				double res = aL > bL ? aL : bL; // max(aL, bL)
				// if n+m even - median is average between 2 elements in the middle
				if ((n + m) % 2 == 0) {
					res += aR < bR ? aR : bR; // min(aR, bR)
					res /= 2.;
				}
				return res;
			}

			// check if smaller elements in a[] should be next
			if (aL > bR) {
				hi = ma - 1;
			}
			// or the bigger ones should be next
			else {
				lo = ma + 1;
			}
		}

		return 0.;
	}
};

const char* pritnVec(const vector<int>& v) {
	std::cout << "[ ";
	for (int e : v) {
		std::cout << e << ' ';
	}
	std::cout << ']';
	return "";
}

int main() {
	Solution sol;

	{
		vector<int> a = {1, 3};
		vector<int> b = {2};
		double res = sol.findMedianSortedArrays(a, b);
		std::cout << "  a=" << pritnVec(a) << '\n'
				  << "  b=" << pritnVec(b) << '\n'
				  << "res=" << res << "\n\n";
	}

	{
		vector<int> a = {1, 2};
		vector<int> b = {3, 4};
		double res = sol.findMedianSortedArrays(a, b);
		std::cout << "  a=" << pritnVec(a) << '\n'
				  << "  b=" << pritnVec(b) << '\n'
				  << "res=" << res << "\n\n";
	}

	{
		vector<int> a = {1,1,1,1,1,1,1,1,1,1,1};
		vector<int> b = {2};
		double res = sol.findMedianSortedArrays(a, b);
		std::cout << "  a=" << pritnVec(a) << '\n'
				  << "  b=" << pritnVec(b) << '\n'
				  << "res=" << res << "\n\n";
	}

	{
		vector<int> a = {6};
		vector<int> b = {};
		double res = sol.findMedianSortedArrays(a, b);
		std::cout << "  a=" << pritnVec(a) << '\n'
				  << "  b=" << pritnVec(b) << '\n'
				  << "res=" << res << "\n\n";
	}

	{
		vector<int> a = {1,1,1,1,1,1,1,3,3,3,3,3,3,3};
		vector<int> b = {2,2};
		double res = sol.findMedianSortedArrays(a, b);
		std::cout << "  a=" << pritnVec(a) << '\n'
				  << "  b=" << pritnVec(b) << '\n'
				  << "res=" << res << "\n\n";
	}

	{
		vector<int> a = {3,4,6,8,9,10,13,15,16};
		vector<int> b = {1,2,5,7,11,12,14};
		double res = sol.findMedianSortedArrays(a, b);
		std::cout << "  a=" << pritnVec(a) << '\n'
				  << "  b=" << pritnVec(b) << '\n'
				  << "res=" << res << "\n\n";
	}

	{
		vector<int> a = {2,5,7,8};
		vector<int> b = {1,4,9};
		double res = sol.findMedianSortedArrays(a, b);
		std::cout << "  a=" << pritnVec(a) << '\n'
				  << "  b=" << pritnVec(b) << '\n'
				  << "res=" << res << "\n\n";
	}

	return 0;
}