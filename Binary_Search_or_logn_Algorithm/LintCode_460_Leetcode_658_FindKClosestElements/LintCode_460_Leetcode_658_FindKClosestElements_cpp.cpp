// Lintcode Solution time O(logn + k)
class Solution {
public:
	/**
	* @param A: an integer array
	* @param target: An integer
	* @param k: An integer
	* @return: an integer array
	*/
	vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
		// write your code here
		if (A.empty() || k <= 0 || k > A.size()) {
			return{};
		}

		int start = 0, end = A.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (A[mid] > target) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		vector<int> result(k);
		for (int i = 0; i < k; i++) {
			if (start < 0) {
				result[i] = A[end++];
			}
			else if (end >  A.size() - 1) {
				result[i] = A[start--];
			}
			else {
				if (target - A[start] <= A[end] - target) {
					result[i] = A[start--];
				}
				else {
					result[i] = A[end++];
				}
			}
		}
		return result;
	}
};

// Leetcode Solution time O(logn + k)
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		if (arr.empty() || k == 0 || k > arr.size()) {
			return{};
		}
		if (arr.size() == 1) {
			return arr;
		}

		int start = 0, end = arr.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (arr[mid] > x) {
				end = mid;
			}
			else {
				start = mid;
			}
		}

		for (int i = 0; i < k; i++) {
			if (start < 0) {
				end++;
			}
			else if (end > arr.size() - 1) {
				start--;
			}
			else {
				if (x - arr[start] <= arr[end] - x) {
					start--;
				}
				else {
					end++;
				}
			}
		}
		vector<int> result(arr.begin() + start + 1, arr.begin() + end);
		return result;
	}
};