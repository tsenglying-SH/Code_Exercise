// binary search, time O(logn)
class Solution {
public:
	int getMissingNumber(vector<int>& nums) {
		if (nums.empty()) return 0;
		int l = 0, r = nums.size() - 1;
		// the corner case like [1, 2, 3, 4, 5, 6] or [0, 1, 2, 3, 4, 5] is included
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == mid) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return l;
	}
};