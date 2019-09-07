// two pointers time O(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.size() <= 1) {
			return{ -1, -1 };
		}

		int i = 0, j = nums.size() - 1;

		while (i + 1 <= j) {
			if (nums[i] + nums[j] == target) {
				return{ i + 1, j + 1 };
			}
			else if (nums[i] + nums[j] > target) {
				j--;
			}
			else {
				i++;
			}
		}
		return{ -1, -1 };
	}
};