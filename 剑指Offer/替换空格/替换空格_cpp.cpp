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
	// here length means string's length, rewrite may cause memory overlap
	void replaceSpace(char *str, int length) {
		if (length <= 0 || str == nullptr) {
			return;
		}
		int space_cnt = 0;
		for (int i = 0; i < length; ++i) {
			if (str[i] == ' ') {
				++space_cnt;
			}
		}
		int new_len = length + 2 * space_cnt;

		// here may cause memory overlap
		// notice cstring char array end with '\0', so 1 more length
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

class Solution {
public:
	// if length means char array's capacity, we can avoid memory overlap, when overlap happens, just give up replacing
	void replaceSpace(char *str, int length) {
		if (length <= 0) return;
		int i = 0;
		while (str[i] != '\0') ++i;

		int old_len = i + 1, new_len = old_len;
		for (int i = 0; i < old_len; ++i) {
			if (str[i] == ' ') new_len += 2;
		}
		// str capacity too small, may cause memory overlap
		if (new_len > length) return;
		// notice cstring char array end with '\0'
		int old_p = old_len, new_p = new_len;
		while (old_p >= 0 && new_p >= 0) {
			if (str[old_p] != ' ') str[new_p--] = str[old_p--];
			else {
				str[new_p--] = '0';
				str[new_p--] = '2';
				str[new_p--] = '%';
				old_p--;
			}
		}
	}
};