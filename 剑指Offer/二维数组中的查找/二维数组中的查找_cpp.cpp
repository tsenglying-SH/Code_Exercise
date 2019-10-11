// time O(row + col), no extra space
class Solution {
public:
	bool searchArray(vector<vector<int>> array, int target) {
		if (array.empty() || array[0].empty()) {
			return false;
		}

		int col = array[0].size() - 1, row = 0;

		while (row <= array.size() - 1 && col >= 0) {
			if (array[row][col] == target) {
				return true;
			}
			else if (array[row][col] > target) {
				col--;
			}
			else {
				row++;
			}
		}
		return false;
	}
};