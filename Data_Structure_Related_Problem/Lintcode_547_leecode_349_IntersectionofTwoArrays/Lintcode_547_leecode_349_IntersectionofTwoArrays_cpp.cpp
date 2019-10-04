//unordered_set based method, tricky way use erase, time O(m + n)
class Solution {
public:
	/**
	* @param nums1: an integer array
	* @param nums2: an integer array
	* @return: an integer array
	*/
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
		// write your code here
		vector<int> res;
		unordered_set<int> set1(nums1.begin(), nums1.end());
		for (int i = 0; i < nums2.size(); i++) {
			if (set1.erase(nums2[i])) {
				res.push_back(nums2[i]);
			}
		}
		return res;
	}
};

// sort + 2 pointers, time O(nlogn + mlogm + m + n)
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty()) {
			return{};
		}
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		int m = nums1.size(), n = nums2.size(), i = 0, j = 0;
		vector<int> res;
		while (i < m && j < n) {
			if (nums1[i] == nums2[j]) {
				res.push_back(nums1[i]);
				i++; j++;
				while (i < m && nums1[i] == nums1[i - 1]) {
					i++;
				}
				while (j < n && nums2[j] == nums2[j - 1]) {
					j++;
				}
			}
			else if (nums1[i] > nums2[j]) {
				j++;
			}
			else if (nums1[i] < nums2[j]) {
				i++;
			}
		}
		return res;
	}
};

// sort + binary_search, time O(mlogm + nlogm)
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty()) {
			return{};
		}
		if (nums1.size() > nums2.size()) {
			return intersection(nums2, nums1);
		}
		// mlogm
		sort(nums1.begin(), nums1.end());
		unordered_set<int> res_set;

		// nlogm
		for (int num : nums2) {
			if (binary_search(nums1, num)) {
				res_set.insert(num);
			}
		}
		return vector<int>(res_set.begin(), res_set.end());
	}

	bool binary_search(vector<int> &num_list, int num) {
		if (num_list.empty()) {
			return false;
		}
		int start = 0, end = num_list.size() - 1;

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (num_list[mid] >= num) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		return num_list[start] == num || num_list[end] == num;
	}
};