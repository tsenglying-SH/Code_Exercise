// binary method including bit operate, time O(logn), when n == INT_MIN, it's really a corner case, deal it.
class Solution {
public:
	double myPow(double x, int n) {
		if (x == 1 || n == 0) {
			return 1;
		}
		if (x == 0) {
			return 0;
		}
		// an important corner case, can't just do n = -n
		if (n == INT_MIN) {
			return myPow(1 / x, INT_MAX) * 1 / x;
		}

		// deal with other negative n
		if (n < 0) {
			x = 1 / x;
			n = -n;
		}

		double res = 1;
		while (n > 0) {
			// whether n is odd
			if (n & 1) {
				res *= x;
			}
			x *= x;
			// >> 1 or / 2
			n >>= 1;
		}
		return res;
	}
};