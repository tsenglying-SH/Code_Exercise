// DP1 Time O(n^2), Space O(n)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		int n = nums.size();
		vector<int> dp(n, 1);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}

		int res = 0;
		for (int num : dp) {
			res = max(res, num);
		}
		return res;
	}
};

// O(nlogn) method, We can also implement the binary search ourselves
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		int n = nums.size();
		vector<int> dp(n, INT_MAX);
		dp[0] = nums[0];
		int size = 1;

		for (int num : nums) {
			int start = 0, end = size - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (dp[mid] >= num) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			dp[start] = num;
			if (start >= size) {
				size++;
			}
		}
		return size;
	}
};
// O(nlogn) method, we can do it in place via some space optimization
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		int n = nums.size();
		// vector<int> dp(n, INT_MAX);
		// dp[0] = nums[0];
		int size = 1;

		for (int num : nums) {
			int start = 0, end = size - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (nums[mid] >= num) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			nums[start] = num;
			if (start >= size) {
				size++;
			}
		}
		return size;
	}
};


// O(nlogn) method, we can also do it in place via STL
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
