// DP method, with space optimized, time O(n), space O(1)
// example: [-2,2,-3,4,-1,2,1,-5,3], corresponding dp array is [-2, 2, -1, 4, 3, 5, 6, 1, 4]
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: An integer indicate the sum of max subarray
	*/
	int maxSubArray(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return 0;
		}

		int cur_sum = nums[0], max_sum = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (cur_sum < 0) {
				cur_sum = nums[i];
			}
			else {
				cur_sum += nums[i];
			}
			if (cur_sum > max_sum) {
				max_sum = cur_sum;
			}
		}
		return max_sum;
	}
};