// Solution 1: time O(n), space O(n)
class Solution {
public:
	string replaceSpaces(string &str) {
		if (str.empty()) {
			return "";
		}
		int i = 0;
		string res = "";
		while (i < str.size()) {
			if (str[i] != ' ') {
				res += str[i++];
			}
			else {
				res += "%20";
				i++;
			}
		}
		return res;
	}
};

// Solution 2: two pointers, time O(n), space O(1)
class Solution {
public:
	string replaceSpaces(string &str) {
		if (str.empty()) {
			return "";
		}
		int space_cnt = 0;
		for (char c : str) {
			if (c == ' ') {
				space_cnt++;
			}
		}
		// calculate new length, set two pointers, and resize the str
		int new_len = str.size() + 2 * space_cnt;
		int left = str.size() - 1, right = new_len - 1;
		str.resize(new_len);

		// then update the string
		while (left >= 0 && right >= 0) {
			if (str[left] != ' ') {
				str[right--] = str[left--];
			}
			else {
				left--;
				str[right--] = '0';
				str[right--] = '2';
				str[right--] = '%';
			}
		}
		return str;
	}
};

// Solution 3: same algorithm but use cstring, two pointers, time O(n), space O(1);
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (length <= 0) {
			return;
		}
		int space_cnt = 0;
		for (int i = 0; i < length; ++i) {
			if (str[i] == ' ') {
				++space_cnt;
			}
		}
		int new_len = length + 2 * space_cnt;
		// notice cstring char array end with '/0', so 1 more length
		int left = length, right = new_len;

		while (left >= 0 && right >= 0) {
			if (str[left] != ' ') {
				str[right--] = str[left--];
			}
			else {
				--left;
				str[right--] = '0';
				str[right--] = '2';
				str[right--] = '%';
			}
		}
		return;
	}
};