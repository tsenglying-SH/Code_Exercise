// naive dp, time O(n^2), space O(n ^ 2)
class Solution {
public:
	vector<int> numberOfDice(int n) {
		if (n <= 0) return{};
		vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= 6 * i; ++j) {
				for (int k = 1; k <= 6; ++k) {
					if (j >= k) dp[i][j] += dp[i - 1][j - k];
				}
			}
		}
		return vector<int>(dp[n].begin() + n, dp[n].end());
	}
};


// optimized version, time O(n ^ 2), space O(n)
class Solution {
public:
	vector<int> numberOfDice(int n) {
		if (n <= 0) return{};
		vector<int> dp(6 * n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			// update from tail to head
			for (int j = 6 * i; j >= i; --j) {
				// don't forget initialization
				dp[j] = 0;
				for (int k = 1; k <= 6; ++k) {
					if (j - k >= i - 1) dp[j] += dp[j - k];
				}
			}
		}
		return vector<int>(dp.begin() + n, dp.end());
	}
};
