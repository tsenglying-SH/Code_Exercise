// normal way, like dp method, Time O(n)£¬ space O(1)
class Solution {
public:
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int climbStairs(int n) {
		// write your code here
		if (n <= 0) {
			return 0;
		}

		vector<int> dp = { 1, 1 };
		while (n--) {
			int tmp = dp[0] + dp[1];
			dp[0] = dp[1];
			dp[1] = tmp;
		}
		return dp[0];
	}
};


// tricky way, use the format, time O(logn)
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) {
			return 0;
		}
		double sqrt5 = sqrt(5);
		double res = 1 / sqrt5 * (pow((1 + sqrt5) / 2, n) -
			pow((1 - sqrt5) / 2, n));
		return static_cast<int>(res);
	}
};
// tricky way, matrix pow, time O(logn)
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 0) {
			return 0;
		}
		return matrix_pow({ { 1, 1 },{ 1, 0 } }, n + 1)[1][1];

	}

private:
	vector<vector<int>> matrix_multiply(const vector<vector<int>> &A, const vector<vector<int>> &B) {
		if (A.empty() || A[0].empty() || B.empty() || B[0].empty()) {
			return{ { 1, 0 },{ 0, 1 } };
		}

		int m = A.size(), n = A[0].size(), k = B.size(), p = B[0].size();
		if (n != k) {
			return{ { 1, 0 },{ 0, 1 } };
		}

		vector<vector<int>> res(m, vector<int>(p, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < p; ++j) {
				for (int k = 0; k < n; ++k) {
					res[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return res;
	}

	vector<vector<int>> matrix_pow(vector<vector<int>> A, int n) {
		if (n <= 0) {
			return{ { 1, 0 },{ 0, 1 } };
		}

		vector<vector<int>> res = { { 1, 0 },{ 0, 1 } };

		while (n > 0) {
			if (n & 1) {
				res = matrix_multiply(res, A);
			}
			n >>= 1;
			A = matrix_multiply(A, A);
		}
		return res;
	}
};



