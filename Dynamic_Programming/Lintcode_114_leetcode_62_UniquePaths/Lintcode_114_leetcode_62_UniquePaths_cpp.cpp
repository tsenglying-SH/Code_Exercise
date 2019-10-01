// Basic DP, can optimize the space complexity
class Solution {
public:
	/**
	* @param m: positive integer (1 <= m <= 100)
	* @param n: positive integer (1 <= n <= 100)
	* @return: An integer
	*/
	int uniquePaths(int m, int n) {
		// write your code here
		if (m <= 0 || n <= 0) {
			return -1;
		}
		vector<vector<int>> dp(m, vector<int>(n, 1));

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		return dp[m - 1][n - 1];
	}
};

// DP method with optimized space, O(m * n), Space O(n)
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m <= 0 || n <= 0) {
			return -1;
		}
		vector<int> dp(n, 1);

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[j] = dp[j] + dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};