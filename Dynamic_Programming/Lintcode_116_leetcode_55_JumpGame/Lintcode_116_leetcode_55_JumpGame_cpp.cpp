// Greedy method Time O(n), Space O(1)
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty()) {
			return false;
		}

		int max_vld = 0;

		for (int i = 0; i < nums.size(); ++i) {
			// check whether last can be reached first
			if (max_vld >= nums.size() - 1) {
				return true;
			}
			// check whether the index is valid
			if (i > max_vld) {
				break;
			}
			// try updating the max_vld
			max_vld = max(max_vld, nums[i] + i);
		}
		return false;
	}
};