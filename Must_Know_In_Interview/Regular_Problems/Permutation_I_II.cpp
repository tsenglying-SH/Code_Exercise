// leetcode 46 Permutations
// Solution with hash
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty()) return{};
		vector<int> path;
		vector<vector<int>> res;
		unordered_set<int> used;
		dfs(nums, path, res, used, 0);
		return res;
	}

	void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, unordered_set<int> &used, int k) {
		if (k == nums.size()) {
			res.push_back(path);
			return;
		}
		if (k > nums.size()) return;

		for (int i = 0; i < nums.size(); ++i) {
			if (used.count(nums[i])) continue;

			path.push_back(nums[i]);
			used.insert(nums[i]);
			dfs(nums, path, res, used, k + 1);
			used.erase(nums[i]);
			path.pop_back();
		}

	}
};

// we can do it without hash
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty()) return{};
		vector<int> path;
		vector<vector<int>> res;
		dfs(nums, path, res, 0);
		return res;
	}

	void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, int k) {
		if (k == nums.size()) {
			res.push_back(path);
			return;
		}
		if (k > nums.size()) return;

		for (int i = k; i < nums.size(); ++i) {
			path.push_back(nums[i]);
			// save the space of hash
			swap(nums[i], nums[k]);
			dfs(nums, path, res, k + 1);
			swap(nums[i], nums[k]);
			path.pop_back();
		}

	}
};


// leetcode 47 Permutations II
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty()) return{};
		sort(nums.begin(), nums.end());
		vector<int> path;
		vector<vector<int>> res;
		vector<bool> visited(nums.size(), false);
		dfs(nums, path, res, visited, 0);
		return res;
	}

	void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, vector<bool> &visited, int idx) {
		if (idx == nums.size()) {
			res.push_back(path);
			return;
		}
		if (idx > nums.size()) {
			return;
		}

		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i]) continue;

			if (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1]) continue;

			path.push_back(nums[i]);
			visited[i] = true;
			dfs(nums, path, res, visited, idx + 1);
			visited[i] = false;
			path.pop_back();
		}
	}
};