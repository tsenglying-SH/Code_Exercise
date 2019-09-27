// use swap to avoid more space
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty()) {
			return{ {} };
		}
		vector<int> path;
		vector<vector<int>> res;
		dfs(nums, path, res, 0);
		return res;
	}


	void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, int idx) {
		if (idx == nums.size()) {
			res.push_back(path);
			return;
		}
		if (idx > nums.size()) {
			return;
		}

		for (int i = idx; i < nums.size(); i++) {
			path.push_back(nums[i]);
			swap(nums[i], nums[idx]);
			dfs(nums, path, res, idx + 1);
			swap(nums[i], nums[idx]);
			path.pop_back();
		}
	}
};