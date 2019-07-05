class Solution {
public:
	/*
	* @param s: A string
	* @return: A list of lists of string
	*/
	vector<vector<string>> partition(string &s) {
		// write your code here
		vector<vector<string>> result;
		vector<string> path;
		dfs(result, path, s, 0);
		return result;
	}

	void dfs(vector<vector<string>> &result, vector<string> &path,
		const string &s, int idx) {
		if (idx == s.size()) {
			result.push_back(path);
			return;
		}
		if (idx > s.size()) {
			return;
		}

		for (int i = idx; i < s.size(); i++) {
			string prefix = s.substr(idx, i - idx + 1);
			if (is_palindrome(prefix)) {
				path.push_back(prefix);
				dfs(result, path, s, i + 1);
				path.pop_back();
			}
		}
	}
	bool is_palindrome(const string &s) {
		int i = 0;
		int j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};