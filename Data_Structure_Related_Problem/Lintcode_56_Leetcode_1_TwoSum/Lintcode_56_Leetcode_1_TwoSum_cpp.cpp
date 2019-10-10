// hashtable application, time O(n), space O(n)
class Solution {
public:
	/**
	* @param numbers: An array of Integer
	* @param target: target = numbers[index1] + numbers[index2]
	* @return: [index1, index2] (index1 < index2)
	*/
	vector<int> twoSum(vector<int> &numbers, int target) {
		// write your code here
		unordered_map<int, int> hash;
		for (int i = 0; i < numbers.size(); ++i) {
			if (hash.count(target - numbers[i])) {
				return{ hash[target - numbers[i]], i };
			}
			else {
				hash[numbers[i]] = i;
			}
		}
		return{ -1, -1 };
	}
};