struct cmp {
	bool operator()(const vector<int> &a, const vector<int> &b) {
		int diff = a[0] - b[0];
		if (diff == 0) {
			diff = a[1] - b[1];
		}
		if (diff == 0) {
			diff = a[2] - b[2];
		}
		return diff > 0;
	}
};

class Solution {
public:
	/**
	* @param arrays: k sorted integer arrays
	* @return: a sorted array
	*/
	vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
		// write your code here
		if (arrays.empty()) {
			return{};
		}

		priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
		for (int i = 0; i < arrays.size(); ++i) {
			if (!arrays[i].empty()) {
				pq.push({ arrays[i][0], i, 0 });
			}
		}

		vector<int> res;
		while (!pq.empty()) {
			int idx1 = pq.top()[1], idx2 = pq.top()[2]; pq.pop();
			res.push_back(arrays[idx1][idx2]);
			if (idx2 + 1 < arrays[idx1].size()) {
				pq.push({ arrays[idx1][idx2 + 1], idx1, idx2 + 1 });
			}
		}

		return res;
	}
};

// divide conquer method, time O(nlogk), space O(2 * n / k)
class Solution {
public:
	/**
	* @param arrays: k sorted integer arrays
	* @return: a sorted array
	*/
	vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
		// write your code here
		if (arrays.empty()) {
			return{};
		}
		int step = 1, amount = arrays.size();
		while (amount > step) {
			for (int i = 0; i + step < amount; i += 2 * step) {
				arrays[i] = merge2SortedArrays(arrays[i], arrays[i + step]);
			}
			step *= 2;
		}
		return arrays[0];
	}

	vector<int> merge2SortedArrays(const vector<int> &array1, const vector<int> &array2) {
		if (array1.empty()) {
			return array2;
		}
		if (array2.empty()) {
			return array1;
		}
		vector<int> res;
		int i = 0, j = 0, m = array1.size(), n = array2.size();
		while (i < m && j < n) {
			if (array1[i] <= array2[j]) {
				res.push_back(array1[i++]);
			}
			else {
				res.push_back(array2[j++]);
			}
		}
		while (i < m) {
			res.push_back(array1[i++]);
		}
		while (j < n) {
			res.push_back(array2[j++]);
		}
		return res;
	}
};