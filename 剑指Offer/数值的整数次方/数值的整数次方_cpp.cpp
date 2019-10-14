// fast power, O(logn), and pay attention to corner case
class Solution {
private:
	bool input_is_valid = true;

public:
	double Power(double base, int exponent) {
		// pow(0, negative number), 1 / 0 not ok
		if (abs(base) < 0.000001 && exponent < 0) {
			input_is_valid = false;
			return 0;
		}
		// pow(0, 0), we set it to 0
		if (abs(base) < 0.000001 && exponent == 0) {
			return 0;
		}

		// unnecessary to calculate
		if (exponent == 1) {
			return base;
		}

		if (exponent < 0) {
			base = 1.0 / base;
			exponent = -exponent;
		}

		double res = 1;
		while (exponent > 0) {
			if (exponent & 1) {
				res *= base;
			}
			base *= base;
			exponent >>= 1;
		}
		return res;
	}
};