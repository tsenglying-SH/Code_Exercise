// Leetcode 1, use of hash table, time O(n), space O(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.empty()) return{ -1, -1 };
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); ++i) {
			if (hash.find(target - nums[i]) != hash.end()) {
				return{ hash[target - nums[i]], i };
			}
			else hash[nums[i]] = i;
		}
		return{ -1, -1 };
	}
};

// LeetCode 167, sorted array, two pointers, time O(n), space O(1)
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		if (numbers.empty()) return{ -1, -1 };
		int i = 0, j = numbers.size() - 1;

		while (i < j) {
			if (numbers[i] + numbers[j] == target) return{ i + 1, j + 1 };
			else if (numbers[i] + numbers[j] < target) ++i;
			else --j;
		}
		return{ -1, -1 };
	}
};