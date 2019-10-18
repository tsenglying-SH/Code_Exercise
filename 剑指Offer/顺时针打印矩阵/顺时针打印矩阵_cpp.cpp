// for loop is also ok, time O(m * n), space O(1)
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		// corner case
		if (matrix.empty() || matrix[0].empty()) return{};
		// initialize the bound
		int row_max = matrix.size() - 1, row_min = 0, col_max = matrix[0].size() - 1, col_min = 0;
		
		int row = 0, col = 0;
		int d_idx = 0;
		int count = matrix.size() * matrix[0].size();
		vector<int> res;
		while (count) {
			// go (1, 0)
			while (count && col <= col_max) { res.push_back(matrix[row][col++]); --count; }
			--col; ++row;
			// go (0, -1)
			while (count && row <= row_max) { res.push_back(matrix[row++][col]); --count; }
			--row; --col;
			// go (-1, 0)
			while (count && col >= col_min) { res.push_back(matrix[row][col--]); --count; }
			++col; --row;
			// go (0, 1)
			while (count && row > row_min) { res.push_back(matrix[row--][col]); --count; }
			++row; ++col;
			// set the bound smaller
			--row_max; ++row_min;
			--col_max; ++col_min;
		}
		return res;
	}
};