// normal way, like dp method, Time O(n)
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
		double res = 1.0 / sqrt5 * (pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1));
		return static_cast<int>(res);
	}
};
// tricky way, matrix pow, time O(logn)
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) {
			return 0;
		}

		return fast_pow({ { 1, 1 },{ 1, 0 } }, n)[0][0];
	}

	vector<vector<long>> mat_multi(vector<vector<long>> m_a, vector<vector<long>> m_b) {
		if (m_a.empty() or m_a[0].empty() or m_b.empty() or m_b[0].empty() or m_a[0].size() != m_b.size()) {
			return{ {} };
		}

		int m = m_a.size(), n = m_a[0].size(), p = m_b[0].size();
		vector<vector<long>> res(m, vector<long>(p, 0));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < p; ++j) {
				for (int k = 0; k < n; ++k) {
					res[i][j] += m_a[i][k] * m_b[k][j];
				}
			}
		}
		return res;
	}


	vector<vector<long>> fast_pow(vector<vector<long>> mat, int n) {
		if (n == 0) {
			return{ { 1, 0 },{ 0, 1 } };
		}
		if (n == 1) {
			return mat;
		}
		vector<vector<long>> res = { { 1, 0 },{ 0, 1 } };

		while (n > 0) {
			if (n & 1) {
				res = mat_multi(res, mat);
			}
			mat = mat_multi(mat, mat);
			n >>= 1;
		}
		return res;
	}
};



