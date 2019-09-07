// Inplace QuickSort, Time O(nlogn), Space O(1). You may remember the template clearly!
class Solution {
public:
	/**
	* @param A: an integer array
	* @return: nothing
	*/
	void sortIntegers2(vector<int> &A) {
		// write your code here
		partition(A, 0, A.size() - 1);
	}
	void partition(vector<int> &A, int start, int end) {
		if (start > end) {
			return;
		}

		int l = start, r = end;
		int mid = l + (r - l) / 2;
		int pivot = A[mid];

		while (l <= r) {
			while (l <= r && A[l] < pivot) {
				l++;
			}
			while (l <= r && A[r] > pivot) {
				r--;
			}
			if (l <= r) {
				int temp = A[l];
				A[l] = A[r];
				A[r] = temp;
				l++;
				r--;
			}
		}
		partition(A, start, r);
		partition(A, l, end);
	}
};


// Merge Sort time O(nlong) Space O(n), remember this template!
class Solution {
public:
	/**
	* @param A: an integer array
	* @return: nothing
	*/
	void sortIntegers2(vector<int> &A) {
		// write your code here
		if (A.empty()) {
			return;
		}

		vector<int> helper(A.size());
		merge_sort(A, 0, A.size() - 1, helper);
	}

	void merge_sort(vector<int> &A, int start, int end, vector<int> &helper) {
		if (start >= end) {
			return;
		}
		int mid = start + (end - start) / 2;
		merge_sort(A, start, mid, helper);
		merge_sort(A, mid + 1, end, helper);

		merge(A, start, end, helper);
	}

	void merge(vector<int> &A, int start, int end, vector<int> &helper) {
		if (start >= end) {
			return;
		}
		int mid = start + (end - start) / 2;
		int l = start, r = mid + 1, k = start;
		while (l <= mid && r <= end) {
			if (A[l] < A[r]) {
				helper[k++] = A[l++];
			}
			else {
				helper[k++] = A[r++];
			}
		}
		while (l <= mid) {
			helper[k++] = A[l++];
		}

		while (r <= end) {
			helper[k++] = A[r++];
		}

		for (int i = start; i <= end; i++) {
			A[i] = helper[i];
		}
	}
};

// heapsort time O(n log n), space O(n), the important template
class Solution {
public:
	/**
	* @param A: an integer array
	* @return: nothing
	*/
	void sortIntegers2(vector<int> &A) {
		// write your code here
		if (A.empty()) {
			return;
		}

		// build heap
		for (int i = A.size() / 2; i >= 0; i--) {
			down_filt(A, i, A.size() - 1);
		}

		// heap sort
		for (int j = A.size() - 1; j > 0; j--) {
			int tmp = A[j];
			A[j] = A[0];
			A[0] = tmp;
			down_filt(A, 0, j - 1);
		}

	}

	void down_filt(vector<int> &A, int i, int end) {
		int origin = A[i];
		int child = i * 2 + 1;
		while (child <= end) {
			if (child + 1 <= end && A[child + 1] > A[child]) {
				child++;
			}
			// here compare to origin !
			if (A[child] <= origin) {
				break;
			}
			// note the order
			A[i] = A[child];
			i = child;
			child = 2 * i + 1;
		}
		A[i] = origin;
	}
};