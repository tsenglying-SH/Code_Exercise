// only 0-25 can be translated to character, dp method, time O(n)
class Solution {
public:
	int getTranslationCount(string s) {
		if (s.empty()) return -1;
		int n = s.size();
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i - 1];
			if (i > 1) {
				int two_bit = 10 * (s[i - 2] - '0') + (s[i - 1] - '0');
				if (two_bit <= 25 && two_bit >= 10) dp[i] += dp[i - 2];
			}
		}
		return dp[n];
	}
};