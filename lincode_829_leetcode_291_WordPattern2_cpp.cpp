class Solution {
public:
	/**
	* @param pattern: a string,denote pattern string
	* @param str: a string, denote matching string
	* @return: a boolean
	*/
	bool wordPatternMatch(string &pattern, string &str) {
		// write your code here
		unordered_map<char, string> mapping;
		unordered_set<string> used;
		return helper(pattern, str, mapping, used);
	}

	bool helper(const string &pattern, const string &str, unordered_map<char, string> &mapping, unordered_set<string> &used) {
		if (pattern == "" && str == "") {
			return true;
		}
		if (pattern == "" || str == "") {
			return false;
		}

		char cur_char = pattern[0];
		if (mapping.find(cur_char) != mapping.end()) {
			string word = mapping[cur_char];
			if (str.size() < word.size()) {
				return false;
			}
			for (int i = 0; i < word.size(); i++) {
				if (word[i] != str[i]) {
					return false;
				}
			}
			return helper(pattern.substr(1), str.substr(word.size()), mapping, used);
		}

		for (int j = 0; j < str.size(); j++) {
			string cur_word = str.substr(0, j + 1);
			if (used.find(cur_word) != used.end()) {
				continue;
			}

			used.insert(cur_word);
			mapping[cur_char] = cur_word;
			if (helper(pattern.substr(1), str.substr(cur_word.size()), mapping, used)) {
				return true;
			}
			mapping.erase(cur_char);
			used.erase(cur_word);
		}
		return false;
	}
};