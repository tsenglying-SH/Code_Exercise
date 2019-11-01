// tricky via &&, time O(n), space O(n)
class Solution {
public:
	int getSum(int n) {
		int res = n;
		n > 1 && (res += getSum(n - 1));
		return res;
	}
};