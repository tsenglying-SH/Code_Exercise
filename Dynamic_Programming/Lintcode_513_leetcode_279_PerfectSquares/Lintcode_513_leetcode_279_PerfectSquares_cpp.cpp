// DP method, Time O(n^1.5), 108ms, 11.5MB
class Solution {
public:
	int numSquares(int n) {
		// write your code here
		if (n <= 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}

		vector<int> dp_table(n + 1, INT_MAX);
		dp_table[0] = 0;
		dp_table[1] = 1;

		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j * j <= i; j++) {
				dp_table[i] = min(dp_table[i], dp_table[i - j * j] + 1);
			}
		}
		return dp_table.back();
	}
};
// 4 Squares Time O(n^0.5 + logn), 0ms, 8.3MB
class Solution {
public:
	int numSquares(int n) {
		if (n <= 0) {
			return -1;
		}

		while (n % 4 == 0) {
			n /= 4;
		}

		if (n % 8 == 7) {
			return 4;
		}
		// use i * i <= n to avoid sqrt
		for (int i = 0; i * i <= n; ++i) {
		    // here set j to int
			int j = sqrt(n - i * i);
			if (i * i + j * j == n) {
				// tricky way "!!"
				return !!i + !!j;
			}
		}

		return 3;
	}
};

// BFS1, Time O(n^1.5), 332ms, 127.1MB
class Solution {
public:
	int numSquares(int n) {
		if (n < 0) {
			return -1;
		}

		queue<int> Q; Q.push(n);
		int count = 0;

		while (!Q.empty()) {
			int size = Q.size();
			count++;

			while (size--) {
				int num = Q.front(); Q.pop();
				for (int i = static_cast<int>(sqrt(num)); num - i * i >= 0; --i) {
					if (num - i * i == 0) {
						return count;
					}
					Q.push(num - i * i);
				}
			}
		}
		return -1;
	}
};

// BFS2, Time O(n^1,5), 60ms, 14.2MB
class Solution {
public:
	int numSquares(int n) {
		if (n < 0) {
			return -1;
		}
		vector<int> dp(n + 1, n);
		dp[0] = 0;
		queue<int> Q; Q.push(0);

		while (!Q.empty()) {
			int num = Q.front();
			if (num == n) {
				break;
			}
			Q.pop();
			for (int i = 1; num + i * i <= n; ++i) {
				// only better path will be continued
				if (dp[num + i * i] > dp[num] + 1) {
					dp[num + i * i] = dp[num] + 1;
					Q.push(num + i * i);
				}
			}
		}
		return dp[n];
	}
};