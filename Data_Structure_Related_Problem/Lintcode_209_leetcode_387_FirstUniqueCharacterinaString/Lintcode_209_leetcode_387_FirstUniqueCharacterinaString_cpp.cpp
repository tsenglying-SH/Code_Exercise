// use hashtable to count, time O(n), space O(n)
class Solution {
public:
	/**
	* @param str: str: the given string
	* @return: char: the first unique character in a given string
	*/
	char firstUniqChar(string &str) {
		// Write your code here
		unordered_map<char, int> counter;
		for (char c : str) {
			if (counter.count(c)) {
				counter[c]++;
			}
			else {
				counter[c] = 1;
			}
		}
		// here lintcode ask for the char and leetcode ask for the index
		// if the string is so long, the second traverse can be optimized, just traverse the hash map, not the string
		for (char c : str) {
			if (counter.count(c) && counter[c] == 1) {
				return c;
			}
		}
		// here lintcode ask for None, leetcode ask for - 1
		return ' ';
	}
};