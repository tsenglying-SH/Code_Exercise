// vector faster, and the vector's size, n for column and 2n - 1 for sum and diff
class Solution {
private:
	int result = 0;
public:
	/**
	* @param n: The number of queens.
	* @return: The total number of distinct solutions.
	*/
	int totalNQueens(int n) {
		// write your code here
		if (n <= 0) { return 0; }
		vector<int> cols(n, false);
		vector<int> sum(2 * n - 1, false);
		vector<int> diff(2 * n - 1, false);
		search(n, 0, cols, sum, diff);
		return result;
	}
	void search(int n, int level, vector<int> &cols, vector<int> &sum, vector<int> &diff) {
		if (level == n) {
			result += 1;
			return;
		}
		if (level > n) {
			return;
		}

		for (int col = 0; col < n; col++) {
			if (!cols[col] && !sum[level + col] && !diff[n - 1 + level - col]) {
				cols[col] = true;
				sum[level + col] = true;
				diff[n - 1 + level - col] = true;
				search(n, level + 1, cols, sum, diff);
				cols[col] = false;
				sum[level + col] = false;
				diff[n - 1 + level - col] = false;
			}
		}
	}
};