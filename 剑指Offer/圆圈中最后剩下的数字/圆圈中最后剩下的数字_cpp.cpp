// Recursion method, time O(n), space O(n), zero-based
class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n <= 0 || m <= 0) return 0;
		if (n == 1) return 0;
		return (lastRemaining(n - 1, m) + m) % n;
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