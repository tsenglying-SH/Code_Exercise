// lintcode 17  leetcode78 followup , there are some duplicates in set
class Solution {
public:
	/**
	* @param nums: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return{ {} };
		}
		// ascending order;
		sort(nums.begin(), nums.end());
		vector<int> path;
		vector<vector<int>> res;
		dfs(nums, 0, path, res);
		return res;
	}

	void dfs(const vector<int> &nums, int idx, vector<int> &path, vector<vector<int>> &res) {
		// add every path along the way
		res.push_back(path);
		if (idx >= nums.size()) {
			return;
		}

		for (int i = idx; i < nums.size(); i++) {
			// deduplicate
			if (i > idx && nums[i] == nums[i - 1]) {
				continue;
			}

			path.push_back(nums[i]);
			dfs(nums, i + 1, path, res);
			path.pop_back();
		}

	}
};