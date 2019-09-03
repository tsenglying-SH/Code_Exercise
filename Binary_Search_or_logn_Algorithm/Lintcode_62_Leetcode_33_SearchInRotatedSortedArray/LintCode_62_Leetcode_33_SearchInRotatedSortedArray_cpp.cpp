// binary search  time O(logn), the follow up will be hard
class Solution {
public:
	int search(vector<int>& A, int target) {
		if (A.empty()) {
			return -1;
		}

		int start = 0, end = A.size() - 1;

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (target >= A[0]) {
				if (A[mid] > target || A[mid] < A[0]) {
					end = mid;
				}
				else {
					start = mid;
				}
			}
			else {
				if (A[mid] < target || A[mid] >= A[0]) {
					start = mid;
				}
				else {
					end = mid;
				}
			}
		}
		if (A[start] == target) {
			return start;
		}
		if (A[end] == target) {
			return end;
		}
		return -1;
	}
};