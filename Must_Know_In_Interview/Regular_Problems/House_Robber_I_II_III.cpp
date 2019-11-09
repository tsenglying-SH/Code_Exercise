// Leetcode 198 House Robber 
// normal dp, time O(n), space O(n)
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> f(nums.size() + 2, 0);
		for (int i = 0; i < nums.size(); ++i) {
			f[i + 2] = max(f[i + 1], f[i] + nums[i]);
		}
		return f.back();
	}
};
// do the space optimization
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> f(3, 0);
		for (int i = 0; i < nums.size(); ++i) {
			f[0] = f[1];
			f[1] = f[2];
			f[2] = max(f[1], f[0] + nums[i]);
		}
		return f[2];
	}
};
// state machine base dp, time O(n), space O(n)
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		vector<vector<int>> f(n + 1, vector<int>(2, -0x3f3f3f3f));
		f[0][0] = 0;
		for (int i = 1; i <= nums.size(); ++i) {
			f[i][0] = max(f[i - 1][0], f[i - 1][1]);
			f[i][1] = f[i - 1][0] + nums[i - 1];
		}
		return max(f[n][0], f[n][1]);
	}
};
// do the space optimization, time O(n), space O(1)
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		vector<int> f(2, -0x3f3f3f3f);
		f[0] = 0;
		for (int i = 1; i <= nums.size(); ++i) {
			int tmp0 = f[0];
			f[0] = max(f[0], f[1]);
			f[1] = tmp0 + nums[i - 1];
		}
		return max(f[0], f[1]);
	}
};


// Leetcode 213 House Robber II
// naive method, just check head is selected or not, time O(n), space O(1)(space optimization done yet)
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		int n = nums.size();
		// the case didn't pick the first shop
		int f0 = 0, f1 = 0, f2 = 0, f3 = nums[0];
		for (int i = 1; i < n; ++i) {
			f0 = f1;
			f1 = f2;
			f2 = max(f1, f0 + nums[i]);
		}
		// the case picked the first shop
		f0 = 0, f1 = 0;
		for (int i = 1; i < n - 1; ++i) {
			f0 = f1;
			f1 = f3;
			f3 = max(f1, f0 + nums[i]);
		}
		return max(f2, f3);
	}
};

// Leetcode 337 House Robber III
// naive DFS, time O(n), space O(n + logn)(due to hashtable and recursion)
class Solution {
private:
	unordered_map<TreeNode *, unordered_map<int, int>> memo;
public:
	int rob(TreeNode* root) {
		if (!root) return 0;
		dfs(root);
		return max(memo[root][0], memo[root][1]);
	}

	void dfs(TreeNode *root) {
		if (!root) return;
		dfs(root->left);
		dfs(root->right);
		memo[root][1] += root->val;
		if (root->left) {
			memo[root][0] += max(memo[root->left][0], memo[root->left][1]);
			memo[root][1] += memo[root->left][0];
		}
		if (root->right) {
			memo[root][0] += max(memo[root->right][0], memo[root->right][1]);
			memo[root][1] += memo[root->right][0];
		}
	}
};

// optimized DFS, time O(n), O(logn), due to recursion, hashtable is unnecessary
class Solution {
public:
	int rob(TreeNode* root) {
		pair<int, int> r_nr = dfs(root);
		return max(r_nr.first, r_nr.second);
	}

	pair<int, int> dfs(TreeNode *root) {
		if (!root) return{ 0, 0 };
		auto l_r_nr = dfs(root->left);
		auto r_r_nr = dfs(root->right);

		return{ root->val + l_r_nr.second + r_r_nr.second,
			max(l_r_nr.first, l_r_nr.second) + max(r_r_nr.first, r_r_nr.second) };
	}
};