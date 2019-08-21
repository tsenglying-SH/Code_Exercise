// DP method, pay attention to the initialization! in leetcode dp_table use long won't overflow
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		// Corner Cases
		if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
			return 0;
		}
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();

		if (obstacleGrid[m - 1][n - 1] == 1) {
			return 0;
		}

		// Initialization
		vector<vector<long>> dp_table(m, vector<long>(n, 1));

		for (int i = m - 2; i >= 0; i--) {
			if (obstacleGrid[i][n - 1] == 1 || dp_table[i + 1][n - 1] == 0) {
				dp_table[i][n - 1] = 0;
			}
		}

		for (int j = n - 2; j >= 0; j--) {
			if (obstacleGrid[m - 1][j] == 1 || dp_table[m - 1][j + 1] == 0) {
				dp_table[m - 1][j] = 0;
			}
		}

		// Do the DP
		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				if (obstacleGrid[i][j] == 1) {
					dp_table[i][j] = 0;
					continue;
				}
				dp_table[i][j] = dp_table[i + 1][j] + dp_table[i][j + 1];
			}
		}
		cout << dp_table[0][0] << endl;
		return dp_table[0][0];
	}
};