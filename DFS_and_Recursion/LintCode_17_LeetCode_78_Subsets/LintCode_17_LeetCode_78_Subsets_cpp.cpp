// piggy back on DFS with backtracking, time O(n* 2^n)

class Solution {
public:
	/**
	* @param nums: A set of numbers
	* @return: A list of lists
	*/
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return{ {} };
		}
		// remember sorting as asked for in the problem
		sort(nums.begin(), nums.end());

		vector<int> path;
		vector<vector<int>> res;
		dfs(nums, 0, path, res);
		return res;
	}

	void dfs(const vector<int> &nums, int idx, vector<int> &path, vector<vector<int>> &res) {
		// push back every combination along the way, not only the combination at the end of the paths
		res.push_back(path);
		if (idx == nums.size()) { return; }
		if (idx > nums.size()) { return; }

		for (int i = idx; i < nums.size(); i++) {
			path.push_back(nums[i]);
			dfs(nums, i + 1, path, res);
			path.pop_back();
		}
	}
};

// iterative method, time O(n* 2^n)
// example: [[ ]] --> [[ ], [1]] --> [[ ], [1], [2], [1, 2]] --> [[ ], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
class Solution {
public:
	/**
	* @param nums: A set of numbers
	* @return: A list of lists
	*/
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return{ {} };
		}

		vector<vector<int>> res = { {} };
		sort(nums.begin(), nums.end());

		for (int num : nums) {
			int n = res.size();
			for (int i = 0; i < n; i++) {
				res.push_back(res[i]);
				res.back().push_back(num);
			}
		}
		return res;
	}
	}
};

// bit operation method, time O(n* 2^n)
// example: [[], [], [], [], [], [], [], []] -> [[], [1], [], [1], [], [1], [], [1]] -> [[], [1], [2], [1, 2], [], [1], [2], [1, 2]] -> [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]


class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		if (nums.empty()) {
			return{ {} };
		}

		sort(nums.begin(), nums.end());
		int n = nums.size(), p = 1 << n;
		vector<vector<int>> res(p);

		for (int i = 0; i < p; i++) {
			for (int j = 0; j < n; j++) {
				if (i >> j & 1) {
					res[i].push_back(nums[j]);
				}
			}
		}
		return res;
	}
};