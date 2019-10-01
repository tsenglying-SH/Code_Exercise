// DP method, Time O(mn), Space O(mn)
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return -1;
		}

		int m = grid.size(), n = grid[0].size();
		vector<vector<long>> dp(m, vector<long>(n, 0));
		dp[0][0] = grid[0][0];

		for (int j = 1; j < n; ++j) {
			dp[0][j] = grid[0][j] + dp[0][j - 1];
		}

		for (int i = 1; i < m; ++i) {
			dp[i][0] = grid[i][0] + dp[i - 1][0];
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[m - 1][n - 1];
	}
};

// // DP method, Time O(mn), Space O(n)
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return -1;
		}

		int m = grid.size(), n = grid[0].size();
		vector<long> dp(n, 0);
		dp[0] = grid[0][0];

		for (int j = 1; j < n; ++j) {
			dp[j] = grid[0][j] + dp[j - 1];
		}

		for (int i = 1; i < m; ++i) {
			dp[0] += grid[i][0];
			for (int j = 1; j < n; ++j) {
				dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
			}
		}
		return dp[n - 1];
	}
};