// Leetcode 121 Best Time to Buy and Sell Stock
// just do 1 transaction
// time O(n), space O(1)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int cur_min = INT_MAX, res = 0;
		for (int price : prices) {
			cur_min = min(cur_min, price);
			res = max(res, price - cur_min);
		}
		return res;
	}
};

// Leetcode 122 Best Time to Buy and Sell Stock II
// do any transaction you like
// time O(n), space O(1)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int res = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
		}
		return res;
	}
};

// Leetcode123 Best Time to Buy and Sell Stock III
// do at most 2 transactions
// state machine method! time O(n), space O(1)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int INF = 0x3f3f3f3f;
		// initializztion
		int begin = 0, hold_1 = -INF, release_1 = -INF, hold_2 = -INF, release_2 = -INF;
		for (int i = 0; i < prices.size(); ++i) {
			hold_1 = max(hold_1, begin - prices[i]); // choose buy or not
			release_1 = max(release_1, hold_1 + prices[i]); // choose sell or not
			hold_2 = max(hold_2, release_1 - prices[i]); // choose buy again or not
			release_2 = max(release_2, hold_2 + prices[i]); // choose sell again or not
		} 
		return max(release_1, release_2);
	}
};

// Leetcode 188 Best Time to Buy and Sell Stock IV
// do at most k transactions
// state machine method! time O(kn), space O(kn), it may cause TLE MLE
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size(), inf = 0x3f3f3f3f;
		if (k >= n / 2) return maxProfit2(prices);
		vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -inf)));
		for (int i = 0; i <= n; ++i) f[i][0][0] = 0;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
				f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
			}
		}
		int res = 0;
		for (int j = 0; j <= k; ++j) res = max(res, f[n][j][0]);
		return res;
	}
};

// do the space optimization, time O(kn), space O(k), still TLE MLE in some case
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size(), inf = 0x3f3f3f3f;
		if (k >= n / 2) return maxProfit2(prices);
		vector<int> f(2 * k + 2, -inf);
		f[0] = 0; f[1] = 0;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				int tmp1 = max(f[2 * j + 1], f[2 * j - 2] - prices[i - 1]);
				int tmp0 = max(f[2 * j], f[2 * j + 1] + prices[i - 1]);
				f[2 * j + 1] = tmp1;
				f[2 * j] = tmp0;
			}
		}
		return max(f[2 * k], f[2 * k + 1]);
	}
};

// trick, when k >= n / 2, the problem can be solved as Leetcode 122 Best Time to Buy and Sell Stock II
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size(), inf = 0x3f3f3f3f;
		if (k >= n / 2) return maxProfit2(prices);
		vector<int> f(2 * k + 2, -inf);
		f[0] = 0; f[1] = 0;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= k; ++j) {
				f[2 * j + 1] = max(f[2 * j + 1], f[2 * j - 2] - prices[i - 1]);
				f[2 * j] = max(f[2 * j], f[2 * j + 1] + prices[i - 1]);
			}
		}
		return max(f[2 * k], f[2 * k + 1]);
	}

	int maxProfit2(vector<int> &prices) {
		if (prices.empty()) return 0;
		int res = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
		}
		return res;
	}
};

