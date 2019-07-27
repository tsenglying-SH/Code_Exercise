//set based method
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




// hashtable based method
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// write your code here
		vector<int> res;
		if (nums1.size() == 0 || nums2.size() == 0) {
			return res;
		}

		unordered_map<int, int> memo1;
		for (int i = 0; i < nums1.size(); i++) {
			if (memo1.find(nums1[i]) != memo1.end()) {
				memo1[nums1[i]] += 1;
			}
			else {
				memo1[nums1[i]] = 1;
			}
		}

		for (int j = 0; j < nums2.size(); j++) {
			if (memo1.find(nums2[j]) != memo1.end() && memo1[nums2[j]] > 0) {
				memo1[nums2[j]] = 0;
				res.push_back(nums2[j]);
			}
		}
		return res;
	}
};