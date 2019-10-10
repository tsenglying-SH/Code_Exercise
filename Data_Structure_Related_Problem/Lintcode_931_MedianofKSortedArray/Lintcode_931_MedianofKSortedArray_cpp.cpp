// refer to JiuZhang's solution, time O(log(InputRange) * k * log(n))
class Solution {
public:
	/**
	* @param nums: the given k sorted arrays
	* @return: the median of the given k sorted arrays
	*/
	double findMedian(vector<vector<int>> &nums) {
		// write your code here
		if (nums.empty()) {
			return 0;
		}

		int total_len = 0;
		for (int i = 0; i < nums.size(); ++i) {
			total_len += nums[i].size();
		}
		if (total_len == 0) {
			return 0;
		}
		if (total_len & 1) {
			return find_kth(nums, total_len / 2 + 1) * 1.0;
		}
		else {
			return find_kth(nums, total_len / 2) / 2.0 + find_kth(nums, total_len / 2 + 1) / 2.0;
		}
	}

private:
	int find_kth(vector<vector<int>> &nums, int k) {
		int start = INT_MAX, end = INT_MIN;
		for (vector<int> num : nums) {
			if (num.empty()) {
				continue;
			}
			start = min(num[0], start);
			end = max(num.back(), end);
		}

		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			int count = count_smaller_or_equal(nums, mid);
			if (count >= k) {
				end = mid;
			}
			else {
				start = mid;
			}
		}

		if (count_smaller_or_equal(nums, start) >= k) {
			return start;
		}
		return end;
	}

	int count_smaller_or_equal(vector<vector<int>> &nums, int val) {
		int count = 0;
		for (vector<int> &num : nums) {
			count += count_smaller_or_equal_in_array(num, val);
		}
		return count;
	}

	int count_smaller_or_equal_in_array(vector<int> &num, int val) {
		if (num.empty()) {
			return 0;
		}

		int start = 0, end = num.size() - 1;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (num[mid] > val) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		if (num[start] > val) {
			return start;
		}
		if (num[end] > val) {
			return end;
		}
		return num.size();
	}
};

// We can do the binary search more easier! time O(log(InputRange) * k * log(n))
class Solution {
private:
	int total;

	int findKthInArrays(const vector<vector<int>> &nums, int k) {
		if (total == 0) {
			return 0;
		}
		vector<int> start_end = cal_range(nums);
		int start = start_end[0], end = start_end[1];
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (less_equal_than(nums, mid) >= k) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
			// cout << start << endl;
		}
		return start;
	}

	vector<int> cal_range(const vector<vector<int>> &nums) {
		if (total == 0) {
			return{ -1, -1 };
		}
		int start = INT_MAX, end = INT_MIN;
		for (vector<int> num : nums) {
			if (!num.empty()) {
				start = min(num[0], start);
				end = max(num.back(), end);
			}
		}
		return{ start, end };
	}

	int less_equal_than(const vector<vector<int>> &nums, int val) {
		if (total == 0) {
			return 0;
		}
		int count = 0;
		for (const vector<int> & num : nums) {
			count += less_equal_than_in_array(num, val);
		}
		return count;
	}

	int less_equal_than_in_array(const vector<int> &nums, int val) {
		if (nums.empty()) {
			return 0;
		}
		int start = 0, end = nums.size() - 1;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] > val) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		// cout << "count in array" << start << endl; 
		return start;
	}

public:
	/**
	* @param nums: the given k sorted arrays
	* @return: the median of the given k sorted arrays
	*/
	double findMedian(vector<vector<int>> &nums) {
		// write your code here
		total = 0;
		for (const vector<int> & num : nums) {
			total += num.size();
		}
		if (total == 0) {
			return 0;
		}

		if (total & 1) {
			return findKthInArrays(nums, total / 2 + 1);
		}
		else {
			// /2 befor add, to avoid int overflow
			return 1.0 * findKthInArrays(nums, total / 2 + 1) / 2 + 1.0 * findKthInArrays(nums, total / 2) / 2;
			// return 1.0 * (findKthInArrays(nums, total / 2 + 1) + findKthInArrays(nums, total / 2)) / 2;
		}
	}
};