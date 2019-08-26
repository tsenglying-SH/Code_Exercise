class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		// write your code here
		sort(nums.begin(), nums.end());

		int n = nums.size();
		vector<int> dp_table(n, 1);
		vector<int> parents(n, -1);
		int max_len = 0, max_index = -1;

		for (int i = 0; i < n; i++) {
			dp_table[i] = 1;
			parents[i] = -1;
			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0 && dp_table[j] + 1 > dp_table[i]) {
					dp_table[i] = dp_table[j] + 1;
					parents[i] = j;
				}
			}

			if (dp_table[i] > max_len) {
				max_len = dp_table[i];
				max_index = i;
			}
		}

		vector<int> result;
		for (int k = 0; k < max_len; k++) {
			result.push_back(nums[max_index]);
			max_index = parents[max_index];
		}

		return result;
	}
};