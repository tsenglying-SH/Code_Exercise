// time O(nlogn)
// the difficulty is to prove the correctness of the algorithm
// including why it can be sorted and why the sorted combination is the best answer
class Solution {
public:
	static bool cmp(int a, int b) {
		string as = to_string(a), bs = to_string(b);
		return as + bs < bs + as;
	}
	string printMinNumber(vector<int>& nums) {
		if (nums.empty()) return "";
		sort(nums.begin(), nums.end(), cmp);
		string res = "";
		for (int num : nums) {
			res += to_string(num);
		}
		return res;
	}
};

// we can also implement the sort ourselves
class Solution {
public:
	static bool cmp(int a, int b) {
		string as = to_string(a), bs = to_string(b);
		return as + bs < bs + as;
	}
	string printMinNumber(vector<int>& nums) {
		if (nums.empty()) return "";
		partition(nums, 0, nums.size() - 1);
		string res = "";
		for (int num : nums) {
			res += to_string(num);
		}
		return res;
	}
	void partition(vector<int> &nums, int start, int end) {
		if (start >= end) return;
		int l = start, r = end, mid = start + (end - start) / 2;
		int pivot = nums[mid];
		while (l <= r) {
			while (l <= r && cmp(nums[l], pivot)) l++;
			while (l <= r && cmp(pivot, nums[r])) r--;
			if (l <= r) swap(nums[l++], nums[r--]);
		}
		partition(nums, start, r);
		partition(nums, l, end);
	}
};