// log(min(m, n)) method, amazing binary search on Acwing!
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		if (n1 == 0) {
			return findMedian(nums2);
		}
		if (n2 == 0) {
			return findMedian(nums1);
		}
		if (n1 > n2) {
			return findMedianSortedArrays(nums2, nums1);
		}

		int lo = 0, hi = 2 * n1;
		while (lo <= hi) {
			int c1 = lo + ((hi - lo) >> 1);
			int c2 = n1 + n2 - c1;

			double l1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) >> 1];
			double l2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) >> 1];
			double r1 = c1 == 2 * n1 ? INT_MAX : nums1[c1 >> 1];
			double r2 = c2 == 2 * n2 ? INT_MAX : nums2[c2 >> 1];

			if (l1 > r2) {
				hi = c1 - 1;
			}
			else if (l2 > r1) {
				lo = c1 + 1;
			}
			else {
				return 1.0 * (max(l1, l2) + min(r1, r2)) / 2;
			}
		}
		return -1;
	}

	double findMedian(const vector<int> &nums) {
		int size = nums.size();
		if (size & 1) {
			return nums[size >> 1];
		}
		else {
			return 1.0 * (nums[size >> 1] + nums[(size >> 1) - 1]) / 2;
		}
	}
};