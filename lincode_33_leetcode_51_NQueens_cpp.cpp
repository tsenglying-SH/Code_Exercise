class Solution {
public:
	/*
	* @param n: The number of queens
	* @return: All distinct solutions
	*/
	vector<vector<string>> solveNQueens(int n) {
		// write your code here
		vector<vector<string>> results;
		vector<int> path;
		vector<bool> cols(n, false);
		vector<bool> sums(2 * n - 1, false);
		vector<bool> diff(2 * n - 1, false);
		search(n, 0, results, path, cols, sums, diff);
		return results;
	}
	void search(int n, int level, vector<vector<string>> &results, vector<int> &path, vector<bool> &cols, vector<bool> &sums, vector<bool> &diff) {
		if (level == n) {
			results.push_back(draw(path));
			return;
		}
		if (level > n) {
			return;
		}

		for (int col = 0; col < n; col++) {
			if (!cols[col] && !sums[level + col] && !diff[level - col + n - 1]) {
				path.push_back(col);
				cols[col] = true;
				sums[level + col] = true;
				diff[level - col + n - 1] = true;
				search(n, level + 1, results, path, cols, sums, diff);
				cols[col] = false;
				sums[level + col] = false;
				diff[level - col + n - 1] = false;
				path.pop_back();
			}
		}
	}
	vector<string> draw(const vector<int> &path) {
		vector<string> picture;
		int n = path.size();
		for (int i = 0; i < n; i++) {
			string pic_str(n, '.');
			pic_str[path[i]] = 'Q';
			picture.push_back(pic_str);
		}
		return picture;
	}
};