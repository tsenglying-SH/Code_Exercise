class Solution {
public:
	/**
	* @param str: str: the given string
	* @return: char: the first unique character in a given string
	*/
	char firstUniqChar(string &str) {
		// Write your code here
		if (str.size() == 0) { return NULL; }

		unordered_map <char, int> dict;

		for (int i = 0; i < str.size(); i++) {
			if (dict.find(str[i]) != dict.end()) {
				dict[str[i]] += 1;
			}
			else {
				dict[str[i]] = 1;
			}
		}

		for (int i = 0; i < str.size(); i++) {
			if (dict[str[i]] == 1) {
				return str[i];
			}
		}
		return NULL;
	}
};