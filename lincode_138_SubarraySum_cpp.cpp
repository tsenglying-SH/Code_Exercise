// 前缀和的应用 核心在于前i项和与前j项和相等时，i+1到j项的和为0
class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A list of integers includes the index of the first number and the index of the last number
	*/
	vector<int> subarraySum(vector<int> &nums) {
		// write your code here
		vector<int> res_nothing(2, -1);
		if (nums.size() == 0) {
			return res_nothing;
		}

		unordered_map<int, int> memo;
		int prefix_sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			prefix_sum += nums[i];
			if (memo.find(prefix_sum) != memo.end()) {
				vector<int> res;
				res.push_back(memo[prefix_sum] + 1);
				res.push_back(i);
				return res;
			}
			memo[prefix_sum] = i;
		}
		return res_nothing;
	}
};