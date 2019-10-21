// method 1, partition method, time O(n), the number must be the median of the array!
class Solution {
public:
	int moreThanHalfNum_Solution(vector<int>& nums) {
		if (nums.empty()) return -1;
		return partition(nums, 0, nums.size() - 1, (nums.size() + 1) / 2);
	}
	int partition(vector<int> &nums, int start, int end, int k) {
		if (start > end) return -1;
		if (start == end && k == 1) return nums[start];
		int l = start, r = end;
		int mid = l + (r - l) / 2;
		int pivot = nums[mid];

		while (l <= r) {
			while (l <= r && nums[l] < pivot) {
				l++;
			}
			while (l <= r && nums[r] > pivot) {
				r--;
			}
			if (l <= r) {
				swap(nums[l++], nums[r--]);
			}
		}

		if (start + k - 1 <= r) {
			return partition(nums, start, r, k);
		}
		else if (start + k - 1 >= l) {
			return partition(nums, l, end, k - l + start);
		}
		else {
			return pivot;
		}
	}
};

// really tricky way, time O(n)
class Solution {
public:
	int moreThanHalfNum_Solution(vector<int>& nums) {
		if (nums.empty()) return -1;
		int val = nums[0], cnt = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (cnt == 0) {
				cnt = 1;
				val = nums[i];
			}
			else if (nums[i] == val) {
				cnt++;
			}
			else {
				cnt--;
			}
		}
		return val;
	}
};