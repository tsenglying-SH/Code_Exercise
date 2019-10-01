// DP method, pay attention to the initialization! in leetcode dp_table use long won't overflow
// Time O(m * n), Space O(m * n)
class Solution {
public:
	/**
	* @param obstacleGrid: A list of lists of integers
	* @return: An integer
	*/
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
		// write your code here
		if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
			return -1;
		}
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<long>> dp(m, vector<long>(m, 0));

		// initilization
		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0] == 0) {
				dp[i][0] = 1;
			}
			else {
				break;
			}
		}

		for (int j = 0; j < n; j++) {
			if (obstacleGrid[0][j] == 0) {
				dp[0][j] = 1;
			}
			else {
				break;
			}
		}
		// do the DP
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 0) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

// Optimized version, Time O(m * n), Space O(n)
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& grid) {
		if (grid.empty() | grid[0].empty()) {
			return -1;
		}

		int m = grid.size(), n = grid[0].size();
		vector<long> dp(n, 0);

		for (int j = 0; j < n; ++j) {
			if (grid[0][j] == 0) {
				dp[j] = 1;
			}
			else {
				break;
			}
		}

		for (int i = 1; i < m; i++) {
			if (grid[i][0] == 1) {
				dp[0] = 0;
			}
			for (int j = 1; j < n; j++) {
				if (grid[i][j] == 0) {
					dp[j] = dp[j] + dp[j - 1];
				}
				else {
					dp[j] = 0;
				}
			}
		}

		return dp[n - 1];

	}
};