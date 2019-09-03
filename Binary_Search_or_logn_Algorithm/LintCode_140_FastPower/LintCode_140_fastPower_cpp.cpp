// When using cpp, pay attention to int overflow. Time O(logn)
class Solution {
public:
	/**
	* @param a: A 32bit integer
	* @param b: A 32bit integer
	* @param n: A 32bit integer
	* @return: An integer
	*/
	int fastPower(int a, int b, int n) {
		// write your code here
		if (n == 0 || a == 1) {
			return 1 % b;
		}
		if (a == 0) {
			return 0;
		}

		long res = 1 % b;
		long tmp = a;
		while (n > 0) {
			if (n & 1) {
				res = ((res % b) * (tmp % b)) % b;
			}

			tmp = (tmp % b) * (tmp % b);
			n >>= 1;
		}
		return res % b;
	}
};