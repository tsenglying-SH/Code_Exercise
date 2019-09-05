// do write opreation as few as possible
class Solution {
public:
	/**
	* @param nums: an integer array
	* @return: nothing
	*/
	void moveZeroes(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return;
		}

		int slow = 0, fast = 0;

		while (fast < nums.size()) {
			if (nums[fast] != 0) {
				if (fast != slow) {
					nums[slow] = nums[fast];
				}
				slow++;
			}
			fast++;
		}

		while (slow < nums.size()) {
			if (nums[slow] != 0) {
				nums[slow] = 0;
			}
			slow++;
		}

	}
};