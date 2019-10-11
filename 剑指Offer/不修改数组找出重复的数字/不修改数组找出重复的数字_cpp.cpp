// binary search, time O(nlogn), the space limits O(1)
class Solution {
public:
	int duplicateInArray(vector<int>& nums) {
		int start = 1, end = nums.size();
		while (start <= end) {
			int mid = start + ((end - start) >> 1);
			int count = 0;
			for (int num : nums) {
				if (num <= mid) {
					count++;
				}
			}
			if (count >= mid) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		return start;
	}
};