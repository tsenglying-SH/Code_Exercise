// DP and do the memory suppression
class Solution {
public:
	/**
	* @param grid: a list of lists of integers
	* @return: An integer, minimizes the sum of all numbers along its path
	*/
	int minPathSum(vector<vector<int>> &grid) {
		// write your code here
		if (grid.size() == 0 || grid[0].size() == 0) {
			return 0;
		}
		int m = grid.size(), n = grid[0].size();

		vector<int> cur(n, grid[m - 1][n - 1]);

		for (int i = n - 2; i >= 0; i--) {
			cur[i] = cur[i + 1] + grid[m - 1][i];
		}
		for (int j = m - 2; j >= 0; j--) {
			cur[n - 1] += grid[j][n - 1];
			for (int k = n - 2; k >= 0; k--) {
				cur[k] = grid[j][k] + min(cur[k], cur[k + 1]);
			}
		}
		return cur[0];
	}
};