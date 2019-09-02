//no duplicate in array, so it's easy to solve via binary search, time O(logn)
class Solution {
public:
	/**
	* @param nums: a rotated sorted array
	* @return: the minimum number in the array
	*/
	int findMin(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return -1;
		}

		if (nums.size() == 1) {
			return nums[0];
		}

		// this is an important corner case
		if (nums[0] <  nums.back()) {
			return nums[0];
		}


		int start = 0, end = nums.size() - 1;
		int anchor = nums.back();

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] > anchor) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		return nums[end];
	}
};