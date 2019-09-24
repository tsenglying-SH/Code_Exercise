// search with memory
class Solution {
public:
	/*
	* @param s: A string
	* @param wordDict: A set of words.
	* @return: All possible sentences.
	*/
	vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
		// write your code here
		map<string, vector<string>> cache;
		return dfs(s, wordDict, cache);
	}

	vector<string> dfs(string &s, unordered_set<string> &dict, map<string, vector<string>> &cache) {
		if (cache.count(s) != 0) {
			return cache[s];
		}
		vector<string> res;
		if (s.size() == 0) {
			return res;
		}

		for (int i = 1; i < s.size(); i++) {
			string word = s.substr(0, i);
			if (!dict.count(word)) {
				continue;
			}
			string left = s.substr(i);
			vector<string> sub_result = dfs(left, dict, cache);

			for (int j = 0; j < sub_result.size(); j++) {
				res.push_back(word + ' ' + sub_result[j]);
			}
		}
		if (dict.count(s)) { res.push_back(s); }

		cache[s] = res;

		return res;
	}
};