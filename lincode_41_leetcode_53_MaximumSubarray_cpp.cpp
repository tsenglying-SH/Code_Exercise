class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		int result = INT_MIN, cur_sum = 0;

		for (int num : nums) {
			if (cur_sum < 0) {
				cur_sum = 0;
			}
			cur_sum += num;
			result = max(cur_sum, result);
		}
		return result;
	}
};