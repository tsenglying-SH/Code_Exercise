// partition method, time O(n)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.empty() || k <= 0 || k > nums.size()) return -1;
		return partition(nums, 0, nums.size() - 1, k);
	}

	int partition(vector<int> &nums, int start, int end, int k) {
		if (start > end) return -1;
		if (start == end && k == 1) return nums[start];
		int l = start, r = end, mid = l + (r - l) / 2, pivot = nums[mid];

		while (l <= r) {
			// change the '<' or '>' according to kth largest or kth smallest
			while (l <= r && nums[l] > pivot) ++l;
			while (l <= r && nums[r] < pivot) --r;
			if (l <= r) swap(nums[l++], nums[r--]);
		}

		if (start + k - 1 <= r) return partition(nums, start, r, k);
		else if (start + k - 1 >= l) return partition(nums, l, end, k - l + start);
		else return pivot;
	}
};

// priority queue method, time O(nlogk), space O(k)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.empty() || k <= 0 || k > nums.size()) return -1;
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int num : nums) {
			pq.push(num);
			if (pq.size() > k) pq.pop();
		}
		return pq.top();
	}
};