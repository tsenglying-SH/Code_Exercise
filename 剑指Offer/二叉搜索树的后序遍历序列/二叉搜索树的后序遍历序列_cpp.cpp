class Solution {
public:
	bool verifySequenceOfBST(vector<int> sequence) {
		// the corner case
		if (sequence.empty()) return true;
		return isvalid(sequence, 0, sequence.size() - 1);
	}

	bool isvalid(const vector<int> &seq, int l, int r) {
		if (l >= r) return true;
		int k = l;
		while (k < r && seq[k] < seq[r]) k++;
		for (int idx = k; idx < r; ++idx) {
			if (seq[idx] < seq[r]) return false;
		}
		return isvalid(seq, l, k - 1) && isvalid(seq, k, r - 1);
	}
};