//lintcode题记得要对candidate去重，leetcode就不用，本身输入不含重复元素


class Solution {
public:
	/**
	* @param candidates: A list of integers
	* @param target: An integer
	* @return: A list of lists of integers
	*/
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		// write your code here
		vector<vector<int>> result;
		vector<int> intlist;
		sort(candidates.begin(), candidates.end());
		candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
		dfs(result, intlist, candidates, target, 0);
		return result;
	}

	void dfs(vector<vector<int>> &result, vector<int> &intlist, const vector<int> &candidates, int target, int idx) {
		if (target == 0) {
			result.push_back(intlist);
			return;
		}
		if (target < 0) {
			return;
		}

		for (int i = idx; i < candidates.size(); i++) {
			if (candidates[i] <= target) {
				intlist.push_back(candidates[i]);
				dfs(result, intlist, candidates, target - candidates[i], i);
				intlist.pop_back();
			}
		}
	}
};