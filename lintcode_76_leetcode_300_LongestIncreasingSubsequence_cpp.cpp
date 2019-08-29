// O(n^2)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		// write your code here
		if (nums.empty()) {
			return 0;
		}

		int n = nums.size(), result = 1;
		vector<int> dp_table(n, 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					dp_table[i] = max(dp_table[i], dp_table[j] + 1);
				}
			}
		}

		for (int val : dp_table) {
			if (val > result) {
				result = val;
			}
		}
		return result;
	}
};
// O(nlogn) method, we can do it in place
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		// write your code here
		if (nums.empty()) {
			return 0;
		}

		vector<int>::iterator size = nums.begin();
		for (int & num : nums) {
			auto i = lower_bound(nums.begin(), size, num);
			*i = num;
			if (i == size) {
				size++;
			}
		}
		return size - nums.begin();
	}
};