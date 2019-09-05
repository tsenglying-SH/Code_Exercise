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
		if (numbers == nullptr || length <= 0) {
			return false;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i] < 0 || numbers[i] >= length) {
				return false;
			}
		}

		for (int j = 0; j < length; j++) {
			while (numbers[j] != j) {
				if (numbers[numbers[j]] == numbers[j]) {
					*duplication = numbers[j];
					return true;
				}
				int tmp = numbers[numbers[j]];
				numbers[numbers[j]] = numbers[j];
				numbers[j] = tmp;
			}
		}
		return false;
	}
};


// Vector, Time O(n), Space O(1)
class Solution {
public:
	int duplicateInArray(vector<int>& nums) {
		if (nums.size() == 0) {
			return -1;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > nums.size() - 1 || nums[i] < 0) {
				return -1;
			}
		}

		for (int j = 0; j < nums.size(); j++) {
			while (nums[j] != j) {
				if (nums[nums[j]] == nums[j]) {
					return nums[j];
				}

				int tmp = nums[nums[j]];
				nums[nums[j]] = nums[j];
				nums[j] = tmp;
			}
		}
		return -1;
	}
};