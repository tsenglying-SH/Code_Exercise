// binary search time O(logn)
class Solution {
public:
	/**
	* @param A: An integers array.
	* @return: return any of peek positions.
	*/
	int findPeak(vector<int> &A) {
		// write your code here
		if (A.empty()) {
			return -1;
		}

		int start = 0, end = A.size() - 1;

		while (start + 1 <  end) {
			int mid = (end - start) / 2 + start;
			if (A[mid] > A[mid + 1]) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		return A[start] > A[end] ? start : end;
	}
};