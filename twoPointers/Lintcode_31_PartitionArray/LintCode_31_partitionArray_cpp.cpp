// O(n) partition, the base of Quick Sort
class Solution {
public:
	/**
	* @param nums: The integer array you should partition
	* @param k: An integer
	* @return: The index after partition
	*/
	int partitionArray(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty()) {
			return 0;
		}

		int l = 0, r = nums.size() - 1;
		while (l <= r) {
			while (l <= r && nums[l] < k) {
				l++;
			}
			while (l <= r && nums[r] >= k) {
				r--;
			}
			if (l <= r) {
				swap(nums[l++], nums[r--]);
			}
		}
		return l;
	}
};