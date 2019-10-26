// two pointers, time O(n)
class Solution {
public:
	int longestSubstringWithoutDuplication(string s) {
		if (s.empty()) return 0;
		int i = 0, j = 0, res = 1;
		unordered_set<char> char_used;
		while (j < s.size()) {
			if (char_used.count(s[j])) {
				while (s[i] != s[j]) char_used.erase(s[i++]);
				++i;
			}
			else {
				char_used.insert(s[j]);
			}
			res = max(res, j - i + 1);
			++j;
		}
		return res;
	}
};