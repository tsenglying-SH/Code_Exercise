class Solution {
public:
	/**
	* @param nums: A set of numbers
	* @return: A list of lists
	*/
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		vector<vector<int>> result;
		vector<int> subset;
		sort(nums.begin(), nums.end());
		dfs(result, subset, nums, 0);
		return result;
	}

	void dfs(vector<vector<int>> &result, vector<int> &subset, const vector<int> &nums, int idx) {
		result.push_back(subset);
		if (idx >= nums.size()) {
			return;
		}
		for (int i = idx; i < nums.size(); i++) {
			subset.push_back(nums[i]);
			dfs(result, subset, nums, i + 1);
			subset.pop_back();
		}
	}
};