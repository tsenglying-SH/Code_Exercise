// 2 steps method, time O(n), space O(n)
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		if (A.empty()) return{};
		vector<int> res(A.size(), 1);
		// 1st step
		for (int i = 1; i < A.size(); ++i) {
			res[i] *= res[i - 1] * A[i - 1];
		}
		// 2nd step
		int factor = 1;
		for (int i = A.size() - 2; i >= 0; --i) {
			factor *= A[i + 1];
			res[i] *= factor;
		}

		return res;
	}
};