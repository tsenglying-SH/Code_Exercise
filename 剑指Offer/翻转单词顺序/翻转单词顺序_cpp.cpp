// time O(n), 2 step method
class Solution {
public:
	string reverseWords(string s) {
		// corner case
		if (s.empty()) return "";
		// reverse the whole sentence
		reverse(s.begin(), s.end());
		// reverse every word
		for (int i = 0; i < s.size(); ++i) {
			int j = i;
			while (j < s.size() && s[j] != ' ') ++j;
			reverse(s.begin() + i, s.begin() + j);
			i = j;
		}
		return s;
	}
};