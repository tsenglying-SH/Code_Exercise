// dfs with backtracking, O(C(n, k))
class Solution {
public:
	/**
	* @param n: Given the range of numbers
	* @param k: Given the numbers of combinations
	* @return: All the combinations of k numbers out of 1..n
	*/
	vector<vector<int>> combine(int n, int k) {
		// write your code here
		if (n <= 0 || k <= 0 || n < k) {
			return{ {} };
		}

		vector<int> path;
		vector<vector<int>> res;
		dfs(n, k, path, res, 1);

		return res;
	}

	void dfs(int n, int k, vector<int> &path, vector<vector<int>> &res, int idx) {
		if (k == 0) {
			res.push_back(path);
			return;
		}

		if (k < 0) {
			return;
		}

		for (int i = idx; i <= n; i++) {
			path.push_back(i);
			dfs(n, k - 1, path, res, i + 1);
			path.pop_back();
		}
	}
};