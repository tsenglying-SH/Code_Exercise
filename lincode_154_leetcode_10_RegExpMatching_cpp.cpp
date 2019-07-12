class Solution {
public:
	bool isMatch(string s, string p) {

		int m = s.size();
		int n = p.size();
		bool dp[m + 1][n + 1];
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;

		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*') {
				dp[0][j] = dp[0][j - 2];
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '*') {
					dp[i][j] = ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]) || dp[i][j - 2];
				}
				else {
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};