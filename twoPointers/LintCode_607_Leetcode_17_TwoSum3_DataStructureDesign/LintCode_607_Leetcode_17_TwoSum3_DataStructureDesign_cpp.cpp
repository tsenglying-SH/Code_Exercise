// refresh the traverse of unordered_map..
class TwoSum {
private:
	unordered_map<int, int> hash;

public:
	/**
	* @param number: An integer
	* @return: nothing
	*/
	void add(int number) {
		// write your code here
		if (hash.find(number) != hash.end()) {
			hash[number] += 1;
		}
		else {
			hash[number] = 1;
		}
	}

	/**
	* @param value: An integer
	* @return: Find if there exists any pair of numbers which sum is equal to the value.
	*/
	bool find(int value) {
		// write your code here

		for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
			int first = it->first;
			int second = value - first;
			if (first != second && hash.find(second) != hash.end()) {
				return true;
			}
			else if (first == second && it->second >= 2) {
				return true;
			}
		}
		return false;
	}
};