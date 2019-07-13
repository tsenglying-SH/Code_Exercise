class Solution {
public:
	/**
	* @param str: A string
	* @return: all permutations
	*/
	vector<string> stringPermutation2(string &str) {
		// write your code here
		vector<string> result;
		sort(str.begin(), str.end()); // 这里一定要记得排序啊！
		vector<bool> visited(str.size(), false);
		dfs(result, "", str, 0, visited);
		return result;
	}

	void dfs(vector<string> &result, const string &path, const string &str, int idx, vector<bool> &visited) {
		if (idx == str.size()) {
			result.push_back(path);
			return;
		}
		if (idx > str.size()) {
			return;
		}
		for (int i = 0; i < str.size(); i++) {
			if (visited[i] == true) { continue; }

			if (i > 0 && str[i - 1] == str[i] && visited[i - 1] == false) {
				continue;
			}

			visited[i] = true;
			dfs(result, path + str[i], str, idx + 1, visited);
			visited[i] = false;
		}
	}
};