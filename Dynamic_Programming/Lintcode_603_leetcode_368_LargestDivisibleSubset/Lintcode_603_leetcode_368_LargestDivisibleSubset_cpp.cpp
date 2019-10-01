// linear DP, Time O(n^2), Space O(n)
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		// corner case
		if (nums.empty()) {
			return{};
		}
		// must sort it!
		sort(nums.begin(), nums.end());

		int n = nums.size(), max_length = 0, max_idx = -1;
		// dp[i] means the maximum length of the subset end with nums[i]
		vector<int> dp(n, 0);
		// record the relations between every elements, used to backtrack and output the final result
		vector<int> sons(n, -1);

		// regard the elements in nums as the largest elements in the subsets
		for (int i = 0; i < n; ++i) {
			dp[i] = 1;
			sons[i] = -1;
			// if some element smaller and nums[i] % nums[j] == 0, try to build a new and larger subsets!
			for (int j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					sons[i] = j;
				}
			}

			// update the answer if the current subset is really bigger
			if (dp[i] > max_length) {
				max_length = dp[i];
				max_idx = i;
			}
		}
		// backtrack and output the result
		vector<int> res;
		for (int k = 0; k < max_length; ++k) {
			res.push_back(nums[max_idx]);
			max_idx = sons[max_idx];
		}
		return res;
	}
};