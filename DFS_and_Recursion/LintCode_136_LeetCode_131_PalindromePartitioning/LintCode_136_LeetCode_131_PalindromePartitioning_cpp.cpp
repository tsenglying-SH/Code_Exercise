// DFS with backtracking
class Solution {
public:
	vector<vector<string>> partition(string s) {
		if (s.size() == 0) {
			return{ {} };
		}

		vector<string> path;
		vector<vector<string>> res;
		dfs(s, 0, path, res);
		return res;
	}

	void dfs(const string &s, int i, vector<string> &path, vector<vector<string>> &res) {
		if (i >= s.size()) {
			res.push_back(path);
			return;
		}

		for (int sub_size = 1; sub_size <= s.size() - i; sub_size++) {
			string sub = s.substr(i, sub_size);
			// cout << sub << " " << is_palindrome(sub) << endl;
			if (is_palindrome(sub)) {
				path.push_back(sub);
				dfs(s, i + sub_size, path, res);
				path.pop_back();
			}
		}
	}

	bool is_palindrome(const string &s) {
		if (s.size() == 0) {
			return true;
		}

		int i = 0, j = s.size() - 1;
		while (i <= j) {
			if (s[i++] != s[j--]) {
				return false;
			}
		}
		return true;
	}
};