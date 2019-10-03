// Quick Selection Time O(n), an important template!
class Solution {
public:
	/**
	* @param n: An integer
	* @param nums: An array
	* @return: the Kth largest element
	*/
	int kthLargestElement(int n, vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return -1;
		}

		return partition(nums, 0, nums.size() - 1, n);
	}

	int partition(vector<int> &nums, int start, int end, int n) {
		if (start >= end && n == 1) {
			return nums[start];
		}

		int l = start, r = end;
		int mid = l + (r - l) / 2;
		int pivot = nums[mid];

		while (l <= r) {
			while (l <= r && nums[l] > pivot) {
				l++;
			}
			while (l <= r && nums[r] < pivot) {
				r--;
			}
			if (l <= r) {
				swap(nums[l++], nums[r--]);
			}
		}

		if (start + n - 1 >= l) {
			return partition(nums, l, end, n - l + start);
		}
		else if (start + n - 1 <= r) {
			return partition(nums, start, r, n);
		}
		return pivot;
	}
};