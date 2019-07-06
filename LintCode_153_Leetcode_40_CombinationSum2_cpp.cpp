class Solution {
public:
	/**
	* @param num: Given the candidate numbers
	* @param target: Given the target number
	* @return: All the combinations that sum to target
	*/
	vector<vector<int>> combinationSum2(vector<int> &num, int target) {
		// write your code here
		vector<vector<int>> result;
		vector<int> comb;
		sort(num.begin(), num.end());
		dfs(result, comb, num, target, 0);
		return result;
	}

	void dfs(vector<vector<int>> &result, vector<int> &comb, const vector<int> &num,
		int target, int idx) {
		if (target == 0) {
			result.push_back(comb);
			return;
		}

		if (target < 0) {
			return;
		}

		for (int i = idx; i < num.size(); i++) {
			if (i > idx && num[i] == num[i - 1]) { continue; }
			if (num[i] <= target) {
				comb.push_back(num[i]);
				dfs(result, comb, num, target - num[i], i + 1);
				comb.pop_back();
			}
		}
	}
};