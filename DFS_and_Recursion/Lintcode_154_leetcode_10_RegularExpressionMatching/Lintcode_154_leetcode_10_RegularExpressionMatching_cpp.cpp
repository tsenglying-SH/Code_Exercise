// DP method, time O(mn)
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;

		// initialize the first row
		for (int j = 1; j <= n; j++) {
			dp[0][j] = p[j - 1] == '*' && j >= 2 && dp[0][j - 2];
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				// attention the index not out of the bound
				if (p[j - 1] != '*') {
					dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
				}
				else {
					// attention the priority of "and" and "or"
					dp[i][j] = j >= 2 && (dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.')));
				}
			}
		}
		return dp[m][n];
	}
};