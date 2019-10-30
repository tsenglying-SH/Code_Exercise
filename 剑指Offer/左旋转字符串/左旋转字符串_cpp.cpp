// 2 step method, time O(n), space O(1)
class Solution {
public:
	string leftRotateString(string str, int n) {
		// corner case
		if (n >= str.size()) return str;
		// reverse the whole string
		reverse(str.begin(), str.end());
		// reverse the first part
		reverse(str.begin(), str.begin() + str.size() - n);
		// reverse the seconde part
		reverse(str.begin() + str.size() - n, str.end());
		return str;
	}
};