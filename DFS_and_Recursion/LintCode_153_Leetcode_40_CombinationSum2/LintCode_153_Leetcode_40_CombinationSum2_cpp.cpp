// dfs with backtracking
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.empty()) {
			return{};
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
			if (i > start_idx && candidates[i] == candidates[i - 1]) {
				continue;
			}
			// avoid useless search
			if (candidates[i] > target) {
				break;
			}

			path.push_back(candidates[i]);
			// subtract the number from target, index should be i + 1, not start_idx related
			dfs(candidates, target - candidates[i], path, res, i + 1);
			path.pop_back();
		}
	}
};