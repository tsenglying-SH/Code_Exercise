// array may contains duplicate, so time O(n) or O(logn)
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty()) {
			return -1;
		}

		int start = 0, end = nums.size() - 1;
		while (nums[start] == nums[end] && end > 0) {
			end--;
		}

		if (nums[start] <= nums[end]) {
			return nums[0];
		}

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] >= nums[0]) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		return nums[end];
	}
};



