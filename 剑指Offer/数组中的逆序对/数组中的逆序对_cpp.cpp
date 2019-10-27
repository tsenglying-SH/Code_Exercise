// piggy back on merge sort, time O(nlogn), space O(n)
class Solution {
private:
	int count = 0;

public:
	int inversePairs(vector<int>& nums) {
		if (nums.empty()) return count;
		merge_sort(nums, 0, nums.size() - 1);
		return count;
	}

	void merge_sort(vector<int> &nums, int start, int end) {
		if (start >= end) return;
		int mid = start + (end - start) / 2;
		merge_sort(nums, start, mid);
		merge_sort(nums, mid + 1, end);
		merge(nums, start, mid, end);
	}

	void merge(vector<int> &nums, int start, int mid, int end) {
		if (start >= end) return;
		int i = start, j = mid + 1, k = start;
		vector<int> helper(nums.size());
		while (i <= mid && j <= end) {
			if (nums[i] <= nums[j]) {
				helper[k++] = nums[i++];
			}
			else {
				count += mid - i + 1;
				helper[k++] = nums[j++];
			}
		}

		while (i <= mid) {
			helper[k++] = nums[i++];
		}
		while (j <= end) {
			helper[k++] = nums[j++];
		}
		for (int idx = start; idx <= end; ++idx) {
			nums[idx] = helper[idx];
		}
	}
};