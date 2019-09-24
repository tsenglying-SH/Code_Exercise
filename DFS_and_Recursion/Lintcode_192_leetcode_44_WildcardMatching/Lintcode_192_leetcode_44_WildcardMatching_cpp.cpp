// search with memo, a little slow
class Solution {
public:
	/**
	* @param s: A string
	* @param p: A string includes "?" and "*"
	* @return: is Match?
	*/
	bool isMatch(string &s, string &p) {
		// write your code here
		map<pair<int, int>, bool> memo;
		return helper(s, 0, p, 0, memo);
	}

	bool helper(const string &s, int i, const string &p, int j, map<pair<int, int>, bool> &memo) {
		if (memo.find(make_pair(i, j)) != memo.end()) {
			return memo[make_pair(i, j)];
		}

		if (i >= s.size()) {
			while (j < p.size()) {
				if (p[j] != '*') {
					return false;
				}
				j++;
			}
			return true;
		}

		if (j >= p.size()) {
			return i >= s.size();
		}

		bool res;
		if (p[j] != '*') {
			res = (p[j] == s[i] || p[j] == '?') && helper(s, i + 1, p, j + 1, memo);
		}
		else {
			res = helper(s, i + 1, p, j, memo) || helper(s, i, p, j + 1, memo);
		}

		memo[make_pair(i, j)] = res;
		return res;
	}
};

// DP method, time O(mn), it's recommended in interview
class Solution {
public:
	/**
	* @param s: A string
	* @param p: A string includes "?" and "*"
	* @return: is Match?
	*/
	bool isMatch(string &s, string &p) {
		// write your code here
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;

		for (int j = 1; j <= n; j++) {
			dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] != '*') {
					dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?');
				}
				else {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};

// a tricky way on Leetcode, I don't want to understand it, and I've forgotten it.
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