// QuickSort Based Method time O(nlogk), Space O(logk)(recurse using stack), it can also be done via Count Sort time O(n), O(k)
class Solution {
public:
	/**
	* @param colors: A list of integer
	* @param k: An integer
	* @return: nothing
	*/
	void sortColors2(vector<int> &colors, int k) {
		// write your code here
		if (colors.empty()) {
			return;
		}

		partition(colors, 0, colors.size() - 1, 1, k);
	}

	void partition(vector<int> &colors, int start, int end, int c1, int c2) {
		// here c1 >= c2 is also important, or it will be infinite recursion
		if (start >= end || c1 >= c2) {
			return;
		}

		int l = start, r = end, pivot = c1 + (c2 - c1) / 2;

		while (l <= r) {
			while (l <= r and colors[l] <= pivot) {
				l++;
			}
			while (l <= r and colors[r] > pivot) {
				r--;
			}
			if (l <= r) {
				//int tmp = colors[r];
				//colors[r] = colors[l];
				//colors[l] = tmp;
				swap(colors[l], colors[r]);
				l++;
				r--;
			}
		}

		partition(colors, start, r, c1, pivot);
		partition(colors, l, end, pivot + 1, c2); // here pivot + 1 is important to make recursive work
	}
};