// classical DFS template
class Solution {
public:
	vector<vector<int>> permutation(vector<int>& nums) {
		if (nums.empty()) return{};

		sort(nums.begin(), nums.end());
		vector<int> path;
		vector<vector<int>> res;
		vector<bool> visited(nums.size(), false);

		dfs(nums, path, res, visited, 0);
		return res;
	}

	void dfs(const vector<int> &nums, vector<int> &path, vector<vector<int>> &res, vector<bool> &visited, int idx) {
		if (idx == nums.size()) {
			res.push_back(path);
			return;
		}
		if (idx > nums.size()) {
			return;
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i]) continue;
			if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

			visited[i] = true;
			path.push_back(nums[i]);
			dfs(nums, path, res, visited, idx + 1);
			path.pop_back();
			visited[i] = false;
		}
	}
};