class Solution {
public:
	/**
	* @param nums: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		// write your code here
		vector<vector<int>> result;
		vector<int> subset;
		sort(nums.begin(), nums.end());
		dfs(result, subset, nums, 0);
		return result;
	}
	void dfs(vector<vector<int>> &result, vector<int> &subset, const vector<int> &nums, int index) {
		result.push_back(subset);
		if (index >= nums.size()) {
			return;
		}

		for (int i = index; i < nums.size(); i++) {
			if (i > index && nums[i] == nums[i - 1]) { continue; }
			subset.push_back(nums[i]);
			dfs(result, subset, nums, i + 1);
			subset.pop_back();
		}
	}
};