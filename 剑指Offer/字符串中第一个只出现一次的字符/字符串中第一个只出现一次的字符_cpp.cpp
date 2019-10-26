// hash map method, time O(n), space O(n)
class Solution {
public:
	char firstNotRepeatingChar(string s) {
		if (s.empty()) return '#';
		unordered_map<char, int> char_cnt;
		for (char c : s) {
			if (char_cnt.count(c)) char_cnt[c]++;
			else char_cnt[c] = 1;
		}

		for (auto c : s) {
			if (char_cnt[c] == 1) return c;
		}
		return '#';
	}
};