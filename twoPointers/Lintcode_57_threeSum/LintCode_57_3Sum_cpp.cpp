// For every elements in array, do two pointers to the elements after it. Time O(n ^ 2)
class Solution {
public:
	/**
	* @param numbers: Give an array numbers of n integer
	* @return: Find all unique triplets in the array which gives the sum of zero.
	*/
	vector<vector<int>> threeSum(vector<int> &numbers) {
		// write your code here
		// corner case
		if (numbers.size() <= 2) {
			return{};
		}

		// sort is necessary before two pointers
		sort(numbers.begin(), numbers.end());
		vector<vector<int>> res;

		for (int i = 0; i < numbers.size(); i++) {
			// eliminate the duplicates
			if (i > 0 && numbers[i] == numbers[i - 1]) {
				continue;
			}

			int l = i + 1, r = numbers.size() - 1;
			int target_sum = -1 * numbers[i];

			while (l < r) {
				if (numbers[l] + numbers[r] == target_sum) {
					// eliminate the duplicates
					if (l == i + 1 || numbers[l] != numbers[l - 1]) {
						res.push_back({ numbers[i], numbers[l], numbers[r] });
					}
					l++; r--;
				}
				else if (numbers[l] + numbers[r] > target_sum) {
					r--;
				}
				else {
					l++;
				}
			}
		}
		return res;
	}
};