// brute force...
class Solution {
public:
	/**
	* @param n: The number of digits
	* @return: All narcissistic numbers with n digits
	*/
	vector<int> getNarcissisticNumbers(int n) {
		// write your code here
		if (n < 0 || n >= 8) {
			return{};
		}
		vector<int> res;
		if (n == 1) {
			res.push_back(0);
		}

		for (int num = pow(10, n - 1); num < pow(10, n); ++num) {
			int sum = 0;
			int num_for_cal = num;
			for (int i = 0; i < n; ++i) {
				int a = num_for_cal % 10;
				sum += pow(a, n);
				num_for_cal /= 10;
			}
			if (sum == num) {
				res.push_back(sum);
			}
		}
		return res;
	}
};