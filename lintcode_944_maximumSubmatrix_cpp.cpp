class Solution {
public:
	/**
	* @param matrix: the given matrix
	* @return: the largest possible sum
	*/
	int maxSubmatrix(vector<vector<int>> &matrix) {
		// write your code here
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return 0;
		}

		int res = matrix[0][0];
		int rows = matrix.size(), cols = matrix[0].size();
		for (int start = 0; start < rows; start++) {
			vector<int> compressed_cols(cols, 0);
			for (int end = start; end < rows; end++) {
				int cur_sum = 0;
				for (int col = 0; col < cols; col++) {
					compressed_cols[col] += matrix[end][col];
					if (cur_sum < 0) {
						cur_sum = 0;
					}
					cur_sum += compressed_cols[col];
					res = max(res, cur_sum);
				}
			}
		}
		return res;
	}
};