// prefix sum, if prefix sum of first i elements equals to prefix sum of first j elements, then add from i + 1 to j equals to 0
// time O(n), space O(1)
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers includes the index of the first number and the index of the last number
	*/
	vector<int> subarraySum(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return{ -1, -1 };
		}

		unordered_map<int, int> sum_idx;
		sum_idx[0] = -1;
		int cur_sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			cur_sum += nums[i];
			if (sum_idx.count(cur_sum)) {
				return{ sum_idx[cur_sum] + 1, i };
			}
			sum_idx[cur_sum] = i;
		}

		return{ -1, -1 };
	}
};