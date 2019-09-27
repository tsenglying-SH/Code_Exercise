// deduplication is the hardest thing here
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty()) {
			return{ {} };
		}
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> path;
		vector<bool> visited(nums.size(), false);
		dfs(nums, path, res, 0, visited);

		return res;
	}

	void dfs(const vector<int> &nums, vector<int> &path, vector<vector<int>> &res, int count, vector<bool> &visited) {
		if (count == nums.size()) {
			res.push_back(path);
			return;
		}

		if (count > nums.size()) {
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (visited[i] == true) {
				continue;
			}

			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
				continue;
			}

			visited[i] = true;
			path.push_back(nums[i]);
			dfs(nums, path, res, count + 1, visited);
			path.pop_back();
			visited[i] = false;
		}
	}
};