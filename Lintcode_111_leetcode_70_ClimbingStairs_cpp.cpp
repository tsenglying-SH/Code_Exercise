// tricky way, use the format
class Solution {
public:
	double climbStairs(int n) {
		if (n <= 0) {
			return 0;
		}

		double sqrt5 = sqrt(5);
		double fib = (pow((sqrt5 + 1) / 2.0, n + 1) - pow((1 - sqrt5) / 2.0, n + 1));
		return int(fib / sqrt5);
	}
};

// normal way

class Solution {
public:
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int climbStairs(int n) {
		// write your code here
		if (n <= 0) {
			return 0;
		}

		vector<int> memo(2);
		memo[0] = 0;
		memo[1] = 1;
		for (int i = 0; i < n; i++) {
			int tmp = memo[0];
			memo[0] = memo[1];
			memo[1] = memo[0] + tmp;
		}
		return memo[1];
	}
};