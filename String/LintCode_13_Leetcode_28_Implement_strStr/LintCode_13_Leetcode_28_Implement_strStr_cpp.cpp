// BF time O(s * t)
class Solution {
public:
	int strStr(string source, string target) {
		if (target.size() == 0) {
			return 0;
		}
		int s = source.size(), t = target.size();
		for (int i = 0; i < s - t + 1; i++) {
			for (int j = 0; j < t; j++) {
				if (source[i + j] != target[j]) {
					break;
				}
				if (j == t - 1 && source[i + j] == target[j]) {
					return i;
				}
			}
		}
		return -1;
	}
};

// Another BF using while, time O(s * t)
class Solution {
public:
	/**
	* @param source:
	* @param target:
	* @return: return the index
	*/
	int strStr(string &source, string &target) {
		// Write your code here
		if (target.size() == 0) {
			return 0;
		}
		int s = source.size(), t = target.size();
		int i = 0, j = 0;
		while (j < t && i < s) {
			if (source[i] == target[j]) {
				i++; j++;
			}
			else {
				i -= j - 1; j = 0;
			}
		}
		return j == t ? i - j : -1;
	}

	//vector<int> buildNext(string &target){

};

// KMP! time O(s +t), amazing!
class Solution {
public:
	/**
	* @param source:
	* @param target:
	* @return: return the index
	*/
	int strStr(string &source, string &target) {
		// Write your code here
		if (target.size() == 0) {
			return 0;
		}
		vector<int> next_table = buildNext(target);
		int m = target.size(), n = source.size();
		int i = 0, j = 0;
		while (j < m && i < n) {
			if (j < 0 || source[i] == target[j]) {
				i++;
				j++;
			}
			else {
				j = next_table[j];
			}
		}
		if (j == m) {
			return i - j;
		}
		return -1;
	}

	vector<int> buildNext(const string &target) {
		int j = 0, t = -1, m = target.size();

		vector<int> next_table(m, 0);
		next_table[0] = -1;

		while (j < m - 1) {
			if (t < 0 || target[j] == target[t]) {
				j++;
				t++;
				next_table[j] = target[j] != target[t] ? t : next_table[t];
			}
			else {
				t = next_table[t];
			}
		}
		return next_table;
	}
};