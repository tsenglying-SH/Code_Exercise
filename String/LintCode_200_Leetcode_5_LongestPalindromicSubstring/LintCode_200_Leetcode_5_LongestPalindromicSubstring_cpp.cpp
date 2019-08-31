// Center Expand method, time O(n^2), space O(1)
class Solution {
public:
	string longestPalindrome(string s) {
		// write your code here
		if (s == "") {
			return "";
		}
		pair<int, int> longest({ 0, 0 });
		for (int i = 0; i < s.size(); i++) {
			for (int j = i; j == i || j == i + 1; j++) {
				pair<int, int> candidate;
				candidate = grow(s, i, j);
				if (candidate.second - candidate.first > longest.second - longest.first) {
					longest = candidate;
				}
			}
		}
		return s.substr(longest.first, longest.second - longest.first);
	}

	pair<int, int> grow(const string &s, int i, int j) {
		while (i > 0 && j < s.size() && s[i - 1] == s[j]) {
			i--;
			j++;
		}
		return{ i, j };
	}
};

// Manacher, time O(n), to be added