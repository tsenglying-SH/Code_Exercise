class Solution {
public:
	/**
	* @param n: Given the range of numbers
	* @param k: Given the numbers of combinations
	* @return: All the combinations of k numbers out of 1..n
	*/
	vector<vector<int>> combine(int n, int k) {
		// write your code here
		vector<vector<int>> result;
		vector<int> comb;
		dfs(result, comb, n, k, 1);
		return result;
	}

	void dfs(vector<vector<int>> &result, vector<int> &comb, int n, int k, int start) {
		if (k == 0) {
			result.push_back(comb);
			return;
		}
		if (k < 0) {
			return;
		}

		for (int i = start; i <= n; i++) {
			comb.push_back(i);
			dfs(result, comb, n, k - 1, i + 1);
			comb.pop_back();
		}
	}
};