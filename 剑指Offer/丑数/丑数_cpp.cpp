// heap based method, time O(nlogn), space O(n)
class Solution {
public:
	int getUglyNumber(int n) {
		priority_queue<int, vector<int>, greater<int>> pq; pq.push(1);
		int res = -1;
		while (n--) {
			res = pq.top(); pq.pop();
			pq.push(res * 2);
			pq.push(res * 3);
			pq.push(res * 5);
			while (pq.top() == res) pq.pop();
		}
		return res;
	}
};

// dp method, time O(n), space O(n)
class Solution {
public:
	int getUglyNumber(int n) {
		if (n <= 0) return 0;
		vector<int> dp(n);
		dp[0] = 1;
		int p2 = 0, p3 = 0, p5 = 0;
		for (int i = 1; i < n; ++i) {
			int candidate = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
			dp[i] = candidate;
			if (candidate == dp[p2] * 2) p2++;
			if (candidate == dp[p3] * 3) p3++;
			if (candidate == dp[p5] * 5) p5++;
		}
		return dp[n - 1];
	}
};