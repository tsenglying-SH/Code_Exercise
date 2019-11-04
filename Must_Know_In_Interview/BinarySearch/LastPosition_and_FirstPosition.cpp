// leetcode 34, lintcode 458 + 14
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		return{ firstPosition(nums, target), lastPosition(nums, target) };
	}


	int lastPosition(vector<int> &nums, int target) {
		// write your code here
		if (nums.empty()) return -1;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] > target) r = mid - 1;
			else l = mid + 1;
		}
		if (r < 0 || nums[r] != target) return -1;
		return r;
	}

	int firstPosition(vector<int> &nums, int target) {
		// write your code here
		if (nums.empty()) return -1;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] >= target) r = mid - 1;
			else l = mid + 1;
		}
		if (l > nums.size() - 1 || nums[l] != target) return -1;
		return l;
	}
};