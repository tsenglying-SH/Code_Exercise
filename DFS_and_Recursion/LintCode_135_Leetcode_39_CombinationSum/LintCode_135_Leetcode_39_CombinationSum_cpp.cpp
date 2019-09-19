//lintcode should deduplicate the candidates

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty()) {
			return{ {} };
		}
		// deduplicate the source candidates vector
		unordered_set<int> candidates_set(candidates.begin(), candidates.end());
		vector<int> path;
		vector<vector<int>> res;
		dfs(candidates_set, target, path, res);

		return res;
	}

	void dfs(const unordered_set<int> &candidates, int target, vector<int> &path, vector<vector<int>> &res) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		if (target < 0) {
			return;
		}

		for (int num : candidates) {
			// num are all positive so check num <= target
			// part after && avoid duplicate path in res
			if (num <= target && (path.empty() || num >= path.back())) {
				path.push_back(num);
				dfs(candidates, target - num, path, res);
				path.pop_back();
			}
		}
	}
};

// leetcode method

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.empty()) {
			return{ {} };
		}

		sort(candidates.begin(), candidates.end());
		vector<int> path;
		vector<vector<int>> res;
		dfs(candidates, target, path, res, 0);

		return res;
	}

	void dfs(const vector<int> &candidates, int target, vector<int> &path, vector<vector<int>> &res, int start_idx) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		if (target < 0) {
			return;
		}

		for (int i = start_idx; i < candidates.size(); i++) {
			// avoid useless search
			if (candidates[i] > target) {
				break;
			}
			path.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], path, res, i);
			path.pop_back();
		}
	}
};