class Solution {
public:
	int longestPalindrome(string s) {
		if (s.size() == 0) {
			return 0;
		}

		unordered_map<char, int> memo;

		for (char c : s) {
			if (memo.find(c) == memo.end()) {
				memo[c] = 1;
			}
			else {
				memo.erase(c);
			}
		}

		int to_remov = memo.size();
		if (to_remov > 0) {
			to_remov -= 1;
		}

		return s.size() - to_remov;
	}
};