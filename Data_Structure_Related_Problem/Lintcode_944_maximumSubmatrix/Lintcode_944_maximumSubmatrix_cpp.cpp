// translate the 2D problem in to 1D problem, time O(n^3), space O(n)
class Solution {
public:
	/**
	* @param matrix: the given matrix
	* @return: the largest possible sum
	*/
	int maxSubmatrix(vector<vector<int>> &matrix) {
		// write your code here
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int m = matrix.size(), n = matrix[0].size(), max_sum = matrix[0][0];

		for (int start_row = 0; start_row < m; ++start_row) {
			vector<int> cur_row(n, 0);
			for (int end_row = start_row; end_row < m; ++end_row) {
				int cur_sum = 0;
				for (int col = 0; col < n; ++col) {
					cur_row[col] += matrix[end_row][col];
					if (cur_sum < 0) {
						cur_sum = 0;
					}
					cur_sum += cur_row[col];
					max_sum = max(max_sum, cur_sum);
				}
			}
		}
		return max_sum;
	}
};