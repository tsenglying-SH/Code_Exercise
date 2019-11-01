// Recursion method, time O(n), space O(n), zero-based
class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n <= 0 || m <= 0) return 0;
		if (n == 1) return 0;
		return (lastRemaining(n - 1, m) + m) % n;
	}
};

// we can also change it into iterative method, time O(n), space O(1)
class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n <= 0 || m <= 0) return 0;
		if (n == 1) return 0;
		int res = 0;
		for (int i = 2; i <= n; ++i) res = (res + m) % i;
		return res;
	}
};

// one-based
class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n <= 0 || m <= 0) return 0;
		if (n == 1) return 1;
		return (lastRemaining(n - 1, m) + m - 1) % n + 1;
	}
};

// we can also change it into iterative method, time O(n), space O(1)
class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n <= 0 || m <= 0) return 0;
		if (n == 1) return 1;
		int res = 1;
		for (int i = 2; i <= n; ++i) res = (res + m - 1) % i + 1;
		return res;
	}
};