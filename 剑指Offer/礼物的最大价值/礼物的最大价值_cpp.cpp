// dp method, time O(m * n), space O(m * n)
class Solution {
public:
	int getMaxValue(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[m][n];
	}
};

// optimize the space, time O(m * n), space O(n)
class Solution {
public:
	int getMaxValue(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[j] = grid[i - 1][j - 1] + max(dp[j], dp[j - 1]);
			}
		}
		return dp[n];
	}
};