// normal DP, time O(mn), space O(mn)
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;

		for (int j = 1; j <= n; ++j) {
			dp[0][j] = j >= 2 && p[j - 2] != '*' && p[j - 1] == '*' && dp[0][j - 2];
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] != '*') {
					dp[i][j] = dp[i - 1][j - 1] && char_match(p[j - 1], s[i - 1]);
				}
				else {
					dp[i][j] = j >= 2 && p[j - 2] != '*' && (dp[i][j - 2] || (dp[i - 1][j] && char_match(p[j - 2], s[i - 1])));
				}
			}
		}
		return dp[m][n];
	}
	bool char_match(char p_c, char s_c) {
		return p_c == s_c || p_c == '.';
	}

};