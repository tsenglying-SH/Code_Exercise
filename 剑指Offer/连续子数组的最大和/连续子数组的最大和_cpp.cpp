// time O(n)
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty()) return 0;
		int val = INT_MIN, sum = 0;
		for (int num : nums) {
			if (sum < 0) sum = 0;
			sum += num;
			val = max(val, sum);
		}
		return val;
	}
};