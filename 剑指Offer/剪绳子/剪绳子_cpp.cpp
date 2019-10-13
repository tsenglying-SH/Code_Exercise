// dp method, time O(n^2), space O(n)
class Solution {
public:
	int maxProductAfterCutting(int length) {
		if (length < 2) { return 0; }
		if (length == 2) { return 1; }
		if (length == 3) { return 2; }
		vector<int> res(length + 1);
		res[1] = 1;
		res[2] = 2;
		res[3] = 3;

		for (int i = 4; i <= length; ++i) {
			int max_product = 0;
			for (int j = 1; j <= i / 2; ++j) {
				int product = res[j] * res[i - j];
				max_product = max(max_product, product);
			}
			res[i] = max_product;
		}
		return res[length];
	}
};

// Greedy, time O(n), space O(1)
// when n >= 5, 3(n - 3) > 2(n - 2) > n
class Solution {
public:
	int maxProductAfterCutting(int length) {
		if (length < 2) { return 0; }
		if (length == 2) { return 1; }
		if (length == 3) { return 2; }
		if (length == 4) { return 4; }

		int res = 1;
		if (length % 3 == 2) { res *= 2; length -= 2; }
		else if (length % 3 == 1) { res *= 4; length -= 4; }

		while (length > 0) {
			res *= 3;
			length -= 3;
		}

		return res;
	}
};