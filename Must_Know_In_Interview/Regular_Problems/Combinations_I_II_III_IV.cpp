// leetcode 39 combinations I, time O(2 ^ n)
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty()) return{};
		vector<int> path;
		vector<vector<int>> res;
		dfs(candidates, path, res, target, 0);
		return res;
	}

	void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, int target, int k) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		if (target < 0) return;

		for (int i = k; i < nums.size(); ++i) {
			// eliminate some use less search
			if (nums[i] > target) continue;
			path.push_back(nums[i]);
			dfs(nums, path, res, target - nums[i], i);
			path.pop_back();
		}
	}
};

// leetcode 40 combinations II, time O(2 ^ n)
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty()) return{};
		sort(candidates.begin(), candidates.end());
		vector<int> path;
		vector<vector<int>> res;
		dfs(candidates, path, res, target, 0);
		return res;
	}

	void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, int target, int k) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		if (target < 0) return;

		for (int i = k; i < nums.size(); ++i) {
			// eliminate duplicates
			if (i > k && nums[i] == nums[i - 1]) continue;
			// eliminate useless duplicates
			if (nums[i] > target) break;
			path.push_back(nums[i]);
			dfs(nums, path, res, target - nums[i], i + 1);
			path.pop_back();
		}
	}
};

// combination sum III
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k <= 0 || n <= 0) return{};
		vector<int> path;
		vector<vector<int>> res;
		dfs(path, res, k, n, 1);
		return res;
	}

	void dfs(vector<int> &path, vector<vector<int>> &res, const int &k, int n, int cur_num) {
		if (path.size() == k && n == 0) {
			res.push_back(path);
			return;
		}
		if (path.size() >= k) return;
		for (int num = cur_num; num < 10; ++num) {
			path.push_back(num);
			dfs(path, res, k, n - num, num + 1);
			path.pop_back();
		}
	}
};


// combination IV, in fact ,it's permutation sum
// use unsigned int to avoid overflow
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty()) return 0;
		sort(nums.begin(), nums.end());
		vector<unsigned int> f(target + 1, 0);
		f[0] = 1;
		for (int j = 1; j <= target; ++j) {
			for (int k = 0; k < nums.size(); ++k) {
				if (k > 0 && nums[k] == nums[k - 1]) continue;
				if (j >= nums[k]) f[j] += f[j - nums[k]];
			}
		}
		return f.back();
	}
};
