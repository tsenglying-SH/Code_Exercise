// Array, Time O(n), Space O(1)
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 0) return false;
		for (int i = 0; i < length; ++i) {
			if (numbers[i] < 0 || numbers[i] > length - 1) return false;
		}

		for (int i = 0; i < length; ++i) {
			while (numbers[numbers[i]] != numbers[i]) {
				swap(numbers[i], numbers[numbers[i]]);
			}
			if (numbers[i] != i) {
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};


// Vector, Time O(n), Space O(1)
class Solution {
public:
	int duplicateInArray(vector<int>& nums) {
		if (nums.empty()) return -1;
		for (int num : nums) {
			if (num < 0 || num > nums.size() - 1) return -1;
		}


		for (int i = 0; i < nums.size(); ++i) {
			while (nums[nums[i]] != nums[i]) {
				swap(nums[nums[i]], nums[i]);
			}
			if (nums[i] != i) return nums[i];
		}
		return -1;
	}
};