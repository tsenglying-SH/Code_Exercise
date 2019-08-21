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
		if (m == 0 || n == 0) {
			return 0;
		}

		vector<vector<int> > dp_table(m, vector<int>(n, 1));
		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				dp_table[i][j] = dp_table[i + 1][j] + dp_table[i][j + 1];
			}
		}
		return dp_table[0][0];
	}
};