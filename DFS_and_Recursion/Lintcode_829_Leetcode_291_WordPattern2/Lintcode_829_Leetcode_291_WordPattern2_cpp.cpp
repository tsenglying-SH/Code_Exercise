// Recursion solution
class Solution {
public:
	/**
	* @param pattern: a string,denote pattern string
	* @param str: a string, denote matching string
	* @return: a boolean
	*/
	bool wordPatternMatch(string &pattern, string &str) {
		// write your code here
		if (pattern.empty() && str.empty()) {
			return true;
		}

		if (pattern.empty() || str.empty()) {
			return false;
		}

		unordered_map<char, string> char_str;
		unordered_set<string> used_str;
		return match(str, 0, pattern, 0, char_str, used_str);
	}

	bool match(const string &str, int i, const string &pattern, int j, unordered_map<char, string> &char_str,
		unordered_set<string> &used_str) {
		if (i >= str.size() && j >= pattern.size()) {
			return true;
		}

		if (i >= str.size() || j >= pattern.size()) {
			return false;
		}

		if (char_str.find(pattern[j]) != char_str.end()) {
			string curr_str = char_str[pattern[j]];
			if (str.substr(i, curr_str.size()) != curr_str) {
				return false;
			}
			return match(str, i + curr_str.size(), pattern, j + 1, char_str, used_str);
		}

		else {
			for (int idx = i + 1; idx <= str.size(); idx++) {
				string new_str = str.substr(i, idx - i);
				if (used_str.find(new_str) == used_str.end()) {
					char_str[pattern[j]] = new_str;
					used_str.insert(new_str);
					if (match(str, idx, pattern, j + 1, char_str, used_str)) {
						return true;
					}
					used_str.erase(new_str);
					char_str.erase(pattern[j]);
				}
			}
		}
		return false;
	}
};