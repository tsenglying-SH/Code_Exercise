// lintcode AC,leetcode warning treated as errors
class Solution {
public:
	/*
	* @param A: An integer array
	* @param B: An integer array
	* @return: a double whose format is *.5 or *.0
	*/
	double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
		// write your code here
		int m = A.size(), n = B.size();
		if (m > n) {
			return findMedianSortedArrays(B, A);
		}

		int imin = 0, imax = m, target_k = (m + n + 1) / 2;

		while (imin <= imax) {
			int i = (imin + imax) / 2;
			int j = target_k - i;

			if (i > 0 && A[i - 1] > B[j]) {
				imax = i - 1;
			}
			else if (i < m && B[j - 1] > A[i]) {
				imin = i + 1;
			}
			else {
				int max_of_left;
				if (i == 0) {
					max_of_left = B[j - 1];
				}
				else if (j == 0) {
					max_of_left = A[i - 1];
				}
				else {
					max_of_left = max(A[i - 1], B[j - 1]);
				}

				if ((m + n) & 1) {
					return max_of_left;
				}

				int min_of_right;
				if (i == m) {
					min_of_right = B[j];
				}
				else if (j == n) {
					min_of_right = A[i];
				}
				else {
					min_of_right = min(A[i], B[j]);
				}
				return (max_of_left + min_of_right) / 2.0;
			}
		}
	}
};

// leetcode AC
class Solution {
public:
	double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
		int m = A.size(), n = B.size();
		if (m > n) {
			return findMedianSortedArrays(B, A);
		}

		int imin = 0, imax = m, target_k = (m + n + 1) / 2;
		double result;
		int max_of_left, min_of_right;
		while (imin <= imax) {
			int i = (imin + imax) / 2;
			int j = target_k - i;

			if (i > 0 && A[i - 1] > B[j]) {
				imax = i - 1;
			}
			else if (i < m && B[j - 1] > A[i]) {
				imin = i + 1;
			}
			else {
				if (i == 0) {
					max_of_left = B[j - 1];
				}
				else if (j == 0) {
					max_of_left = A[i - 1];
				}
				else {
					max_of_left = max(A[i - 1], B[j - 1]);
				}

				if ((m + n) & 1) {
					result = max_of_left;
					break;
				}

				if (i == m) {
					min_of_right = B[j];
				}
				else if (j == n) {
					min_of_right = A[i];
				}
				else {
					min_of_right = min(A[i], B[j]);
				}
				result = (max_of_left + min_of_right) / 2.0;
				break;
			}
		}
		return result;
	}
};