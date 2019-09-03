// binary search time O(logn)
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		if (isBadVersion(1)) {
			return 1;
		}

		int start = 1, end = n;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (isBadVersion(mid)) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		return end;
	}
};