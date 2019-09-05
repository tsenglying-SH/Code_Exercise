// Time O(n), Space O(n)
class Solution {
public:
	/**
	* @param nums: an array of integers
	* @return: the number of unique integers
	*/
	int deduplication(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return 0;
		}

		unordered_set<int> memo;
		int slow = 0, fast = 0;

		while (fast < nums.size()) {
			if (memo.find(nums[fast]) == memo.end()) {
				memo.insert(nums[fast]);
				if (fast != slow) {
					nums[slow] = nums[fast];
				}
				slow++;
			}
			fast++;
			// cout << slow << " " << fast << endl;
		}

		return slow;
	}
};

// time O(nlogn), space O(1)
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}

		if (nums.size() == 1) {
			return 1;
		}


		sort(nums.begin(), nums.end());
		int slow = 1, fast = 1;

		while (fast < nums.size()) {
			if (nums[fast] != nums[fast - 1]) {
				if (fast != slow) {
					nums[slow] = nums[fast];
				}
				slow++;
			}
			fast++;
		}
		return slow;
	}
};