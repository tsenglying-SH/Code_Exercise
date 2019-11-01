// bit operate
class Solution {
public:
	int add(int num1, int num2) {
		int res = 0, carry = 0;
		while (num2) {
			res = num1 ^ num2;
			carry = (num1 & num2) << 1;
			num1 = res;
			num2 = carry;
		}
		return num1;
	}
};