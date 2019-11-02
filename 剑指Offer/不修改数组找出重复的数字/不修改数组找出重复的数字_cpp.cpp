// binary search, time O(nlogn), the space limits O(1)
class Solution {
public:
	int duplicateInArray(vector<int>& nums) {
		if (nums.size() <= 1) return -1;
		int start = 1, end = nums.size() - 1;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			int count = 0;
			for (int num : nums) {
				if (num <= mid && num >= start) ++count;
			}
			// cout << count << endl;
			if (count > mid - start + 1) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
			// cout << start << ' ' << end << endl;
		}
		return start;
	}
};