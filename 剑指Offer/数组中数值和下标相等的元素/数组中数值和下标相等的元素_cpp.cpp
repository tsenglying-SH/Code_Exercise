// notice the corner case
class Solution {
public:
	int getNumberSameAsIndex(vector<int>& nums) {
		if (nums.empty()) return -1;
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] >= mid) r = mid - 1;
			else l = mid + 1;
		}
		// corner case, if the number doesn't exist
		return nums[l] == l ? l : -1;
	}
};