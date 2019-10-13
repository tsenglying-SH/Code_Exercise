// Acwing dfs, time O(3^l * n^2)
class Solution {
public:
	bool hasPath(vector<vector<char>>& matrix, string str) {
		if (matrix.empty() || matrix[0].empty() || str.empty()) {
			return false;
		}

		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (dfs(matrix, str, 0, i, j)) {
					return true;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<char>> &matrix, string str, int idx, int x, int y) {
		if (matrix[x][y] != str[idx]) {
			return false;
		}
		if (idx == str.size() - 1) {
			return true;
		}
		int tmp = matrix[x][y];
		matrix[x][y] = '#';

		vector<int> dx = { 1, 0, -1, 0 }, dy = { 0, 1, 0, -1 };
		for (int i = 0; i < dx.size(); ++i) {
			int new_x = x + dx[i], new_y = y + dy[i];
			if (new_x >= 0 && new_x < matrix.size() && new_y >= 0 && new_y < matrix[0].size()) {
				if (dfs(matrix, str, idx + 1, new_x, new_y)) {
					return true;
				}
			}
		}

		matrix[x][y] = tmp;
		return false;
	}
};