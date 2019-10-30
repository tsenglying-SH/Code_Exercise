// application of Hash table, time O(n), space O(n)
class Solution {
public:
	vector<int> findNumbersWithSum(vector<int>& nums, int target) {
		if (nums.empty()) return{ -1, -1 };
		unordered_map<int, int> num_idx;
		for (int i = 0; i < nums.size(); ++i) {
			if (num_idx.count(target - nums[i])) {
				return{ nums[num_idx[target - nums[i]]], nums[i] };
			}
			else num_idx[nums[i]] = i;
		}
		return{ -1, -1 };
	}
};


// sort + 2 pointers, time O(nlogn), space O(1)
class Solution {
public:
	vector<int> findNumbersWithSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] < target) ++i;
			else if (nums[i] + nums[j] > target) ++j;
			else return{ nums[i], nums[j] };
		}
		return{ -1, -1 };
	}
};