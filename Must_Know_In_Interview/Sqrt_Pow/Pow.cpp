// fast power, time O(logn)
class Solution {
public:
	double myPow(double x, int n) {
		double eps = 0.000001;
		long n_l = n;
		if (abs(x) < eps) return 0;
		if (n_l < 0) n_l = -n_l, x = 1.0 / x;

		double res = 1;
		while (n_l) {
			if (n_l & 1) res *= x;
			x *= x;
			n_l >>= 1;
		}
		return res;
	}
};

// same as above, the difference is the operation when n == INT_MIN
class Solution {
public:
	double myPow(double x, int n) {
		double eps = 0.000001;
		if (abs(x) < eps) return 0;
		double res = 1;
		if (n == INT_MIN) n = INT_MAX, x = 1.0 / x, res = x;
		if (n < 0) n = -n, x = 1.0 / x;
		while (n) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return res;
	}
};