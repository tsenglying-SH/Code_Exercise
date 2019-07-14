// write your code here
sort(nums.begin(), nums.end());
vector<vector<int>> result;
vector<int> path;
vector<bool> visited(nums.size(), false);
dfs(result, path, nums, 0, visited);
return result;
	}
	void dfs(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, int idx, vector<bool> &visited) {
		if (idx == nums.size()) {
			result.push_back(path);
			return;
		}
		if (idx > nums.size()) {
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (visited[i] == true) { continue; }
			path.push_back(nums[i]);
			visited[i] = true;
			dfs(result, path, nums, idx + 1, visited);
			visited[i] = false;
			path.pop_back();
		}
	}