// time O(nlogn) due to sort
class Solution {
public:
	bool isContinuous(vector<int> numbers) {
		// check whether there is five cards
		if (numbers.size() != 5) return false;
		sort(numbers.begin(), numbers.end());
		// check there are at most 4 kings
		int i = 0;
		while (numbers[i] == 0 && i < 5) ++i;
		if (i >= 4) return false;
		// check the cards are within the valid range
		if (numbers[4] - numbers[i] > 4) return false;
		// check there are no duplicates in cards
		for (int idx = i + 1; idx < numbers.size(); ++idx) {
			if (numbers[idx] == numbers[idx - 1]) return false;
		}
		return true;
	}
};