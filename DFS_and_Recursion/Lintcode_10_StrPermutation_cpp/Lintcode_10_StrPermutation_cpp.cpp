// note the difference between permutation and combination
class Solution {
public:
	/**
	* @param str: A string
	* @return: all permutations
	*/
	vector<string> stringPermutation2(string &str) {
		// write your code here
		vector<string> result;
		// remember sort!
		sort(str.begin(), str.end());
		vector<bool> visited(str.size(), false);
		dfs(result, "", str, 0, visited);
		return result;
	}

	void dfs(vector<string> &result, const string &path, const string &str, int idx, vector<bool> &visited) {
		// deduplicate
		if (idx == str.size()) {
			result.push_back(path);
			return;
		}
		// dejump
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