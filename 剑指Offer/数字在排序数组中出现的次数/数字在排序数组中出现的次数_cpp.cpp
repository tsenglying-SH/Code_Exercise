// binary search, time O(logn)
class Solution {
public:
	int getNumberOfK(vector<int>& nums, int k) {
		if (nums.empty()) return 0;
		int up = up_bound(nums, k), low = low_bound(nums, k);
		return up - low;
	}

	int up_bound(const vector<int> &nums, int k) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + ((r - l) >> 1);
			if (nums[mid] > k) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}

	int low_bound(const vector<int> &nums, int k) {
		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			int mid = l + ((r - l) >> 1);
			if (nums[mid] >= k) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}
};