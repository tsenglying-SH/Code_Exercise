// DP method, Time O(n^1.5)
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
// 4 Squares
if (n <= 0) {
	return 0;
}

if (n == 1) {
	return 1;
}

while (n % 4 == 0) {
	n /= 4;
}

if (n % 8 == 7) {
	return 4;
}

for (int i = 0; i * i <= n; i++) {
	int j = static_cast<int>(sqrt(n - i * i));
	if (i * i + j * j == n) {
		return !!i + !!j;
	}
}
return 3;