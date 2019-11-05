// binary search for sqrt
// l + 1 < r template
class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return -1;
		if (x == 0) return 0;
		long long res = 1;
		while (res * res < x) res *= 2;
		if (res * res == x) return res;

		long long l = 0, r = res;
		while (l + 1 < r) {
			long long mid = l + (r - l) / 2;
			if (mid * mid > x) r = mid;
			else l = mid;
		}
		return l;
	}
};

// l <= r template
class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return -1;
		if (x == 0) return 0;
		long res = 1;
		while (res * res < x) res *= 2;
		if (res * res == x) return res;
		long l = 0, r = res;
		while (l <= r) {
			long mid = l + (r - l) / 2;
			if (mid * mid > x) r = mid - 1;
			else l = mid + 1;
		}
		return r;
	}
};

// Newton method for sqrt
class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return -1;
		if (x == 0) return 0;
		double res = 1;
		while (res * res < x) res *= 2;
		while (abs(res * res - x) > 0.01) res = res / 2.0 + x / (2.0 * res);
		return (int)res;
	}
};

