// time O(32n), not the best method
class Solution {
public:
	int findNumberAppearingOnce(vector<int>& nums) {
		if (nums.size() <= 3) return 0;
		vector<int> bit_cnt(32, 0);
		for (int num : nums) {
			for (int i = 0; i < 32; ++i) {
				bit_cnt[i] += num >> i & 1;
			}
		}
		int res = 0;
		for (int j = 0; j < 32; ++j) {
			if (bit_cnt[j] % 3 == 1) res += 1 << j;
		}
		return res;
	}
};

// best method, tricky method, time O(n
class Solution {
public:
	int findNumberAppearingOnce(vector<int>& nums) {
		if (nums.size() <= 3) return 0;
		int one = 0, two = 0;
		for (int num : nums) {
			one = (num ^ one) & ~two;
			two = (num ^ two) & ~one;
		}
		return one;
	}
};)