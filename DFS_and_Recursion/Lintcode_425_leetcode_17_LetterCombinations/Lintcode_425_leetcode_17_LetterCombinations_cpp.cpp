// dfs with backtracking
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		const vector<string> n_to_l = { "", "", "abc", "def",     // '0','1','2',...
			"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		// unordered_map<char, string> n_to_c = { { '2',"abc" },{ '3', "def" },{ '4', "ghi" },{ '5', "jkl" },{ '6', "mno" },{ '7', "pqrs" },{ '8', "tuv" },{ '9', "wxyz" } };
		if (digits == "") { return{}; }
		vector<string> result;
		dfs(result, "", n_to_l, digits, 0);
		return result;
	}

	void dfs(vector<string> &result, const string &path, vector<string> dict, string &digits, int idx) {
		if (idx == digits.size()) {
			result.push_back(path);
			return;
		}
		if (idx > digits.size()) {
			return;
		}

		for (auto c : dict[digits[idx] - '0']) {
			dfs(result, path + c, dict, digits, idx + 1);
		}
	}
};