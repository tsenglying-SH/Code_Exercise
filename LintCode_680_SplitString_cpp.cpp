class Solution {
public:
	/*
	* @param : a string to be split
	* @return: all possible split string array
	*/
	vector<vector<string>> splitString(string& s) {
		// write your code here
		vector<vector<string>> result;
		vector<string> path;
		dfs(result, path, s, 0);
		return result;
	}
private:
	void dfs(vector<vector<string>> &result, vector<string> &path, const string &s, int idx) {
		if (s.size() == idx) {
			result.push_back(path);
			return;
		}
		else if (idx > s.size()) {
			return;
		}
		for (int i = 1; i <= 2; i++) {
			if (idx + i <= s.size()) {
				path.push_back(s.substr(idx, i));
				dfs(result, path, s, idx + i);
				path.pop_back();
			}
		}
	}
};