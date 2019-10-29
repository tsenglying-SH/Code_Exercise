// the application of exclusive OR, time O(n)
class Solution {
public:
	vector<int> findNumsAppearOnce(vector<int>& nums) {
		if (nums.size() < 2) return nums;
		int exclu_or = 0;
		for (int num : nums) {
			exclu_or ^= num;
		}
		int lowbit = exclu_or & -exclu_or;
		int num1 = 0, num2 = 0;
		for (int num : nums) {
			if (num & lowbit) num1 ^= num;
			else num2 ^= num;
		}
		return{ num1, num2 };
	}
};