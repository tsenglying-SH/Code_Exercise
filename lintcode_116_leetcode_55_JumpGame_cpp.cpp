// DP method Time O(n), Space O(1)
class Solution {
public:
	bool canJump(vector<int>& A) {
		if (A.empty()) {
			return false;
		}

		int n = A.size();
		int boundry = 0;

		for (int i = 0; i < n; i++) {
			if (i > boundry) {
				return false;
			}
			if (i + A[i] > boundry) {
				boundry = i + A[i];
			}
			if (boundry >= n - 1) {
				return true;
			}
		}
		return true;
	}
};