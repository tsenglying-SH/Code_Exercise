// Mountain Array, Binary Search, time O(logn)
class Solution {
public:
	/**
	* @param nums: a mountain sequence which increase firstly and then decrease
	* @return: then mountain top
	*/
	int mountainSequence(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return -1;
		}

		int start = 0, end = nums.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] > nums[mid + 1]) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		return max(nums[start], nums[end]);
	}
};