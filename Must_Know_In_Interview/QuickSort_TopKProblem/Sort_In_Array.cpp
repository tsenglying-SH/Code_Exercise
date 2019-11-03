// Quick Sort Template
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		if (nums.empty()) return{};
		partition(nums, 0, nums.size() - 1);
		return nums;
	}
	void partition(vector<int> &nums, int start, int end) {
		if (start > end) return;
		int l = start, r = end;
		int mid = l + (r - l) / 2;
		int pivot = nums[mid];
		while (l <= r) {
			while (l <= r && nums[l] < pivot) ++l;
			while (l <= r && nums[r] > pivot) --r;
			if (l <= r) swap(nums[l++], nums[r--]);
		}
		partition(nums, start, r);
		partition(nums, l, end);
	}
};

// Merge Sort Template
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		if (nums.empty()) return{};
		// declare a helper array in advance to save space
		vector<int> helper(nums.size(), 0);
		mergesort(nums, 0, nums.size() - 1, helper);
		return nums;
	}

	void mergesort(vector<int> &nums, int start, int end, vector<int> &helper) {
		if (start >= end) return;
		int mid = start + (end - start) / 2;

		mergesort(nums, start, mid, helper);
		mergesort(nums, mid + 1, end, helper);

		merge(nums, start, mid, end, helper);
	}
	void merge(vector<int> &nums, int start, int mid, int end, vector<int> &helper) {
		if (start >= end) return;
		int l = start, r = mid + 1, k = start;
		while (l <= mid && r <= end) {
			if (nums[l] <= nums[r]) {
				helper[k++] = nums[l++];
			}
			else {
				helper[k++] = nums[r++];
			}
		}
		while (l <= mid) {
			helper[k++] = nums[l++];
		}
		while (r <= end) {
			helper[k++] = nums[r++];
		}

		for (int i = 0; i < end - start + 1; ++i) {
			nums[start + i] = helper[start + i];
		}
	}
};

// heap sort template
class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		if (nums.empty()) return{};

		for (int i = nums.size() / 2; i >= 0; --i) {
			downfilt(nums, i, nums.size() - 1);
		}

		for (int i = nums.size() - 1; i >= 1; --i) {
			swap(nums[0], nums[i]);
			downfilt(nums, 0, i - 1);
		}
		return nums;
	}

	void downfilt(vector<int> &nums, int idx, int up_bound) {
		int origin_val = nums[idx];
		int child = 2 * idx + 1;
		while (child <= up_bound) {
			if (child + 1 <= up_bound && nums[child + 1] > nums[child]) child++;
			if (origin_val > nums[child]) break;
			nums[idx] = nums[child];
			idx = child;
			child = child * 2 + 1;
		}
		nums[idx] = origin_val;
	}
};