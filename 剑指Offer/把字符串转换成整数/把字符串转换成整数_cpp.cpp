// just a grammar problem from Acwing
class Solution {
public:
	int strToInt(string str) {
		// corner case
		if (str.empty()) return 0;
		long long num = 0;
		int p_s = 0;
		bool negative = false;
		// eliminate space
		while (p_s < str.size() && str[p_s] == ' ') ++p_s;
		// check + or - or illegal input
		if (str[p_s] == '-') negative = true, ++p_s;
		else if (str[p_s] == '+') ++p_s;
		else if (!(str[p_s] <= '9' && str[p_s] >= '0')) return 0;
		while (p_s < str.size()) {
			int minus = negative ? -1 : 1;
			if (str[p_s] <= '9' && str[p_s] >= '0') {
				num = num * 10 + minus * (str[p_s] - '0');
			}
			// check overflow
			if (num > INT_MAX) return INT_MAX;
			if (num < INT_MIN) return INT_MIN;
			++p_s;
		}
		return num;
	}
};