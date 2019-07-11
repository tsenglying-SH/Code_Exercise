class Solution {
public:
	/**
	* @param s: A string
	* @param p: A string includes "?" and "*"
	* @return: is Match?
	*/
	bool isMatch(string &s, string &p) {
		// write your code here
		int i = 0, j = 0, star = -1, match = -1;
		while (i < s.size()) {
			if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
				i++;
				j++;
			}
			else if (j < p.size() && p[j] == '*') {
				star = j++;
				match = i;
			}
			else if (star != -1) {
				j = star + 1;
				i = ++match;
			}
			else {
				return false;
			}
		}
		while (j < p.size() && p[j] == '*') {
			j++;
		}
		return j == p.size();
	}
};