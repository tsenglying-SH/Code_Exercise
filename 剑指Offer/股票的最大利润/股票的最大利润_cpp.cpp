// time O(n)
class Solution {
public:
	int maxDiff(vector<int>& nums) {
		if (nums.empty()) return 0;
		int res = 0, cur_min = nums[0];
		for (int i = 0; i < nums.size(); ++i) {
			cur_min = min(cur_min, nums[i]);
			res = max(res, nums[i] - cur_min);
		}
		return res;
	}
};