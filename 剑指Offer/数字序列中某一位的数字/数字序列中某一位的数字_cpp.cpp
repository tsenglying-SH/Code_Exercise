// time O(logn)
class Solution {
public:
	int digitAtIndex(int n) {
		// corner cases
		if (n < 0) return -1;
		if (n == 0) return 0;
		// Bit_num means how many bits the num has,and bit_cnt means the amount of numbers which are with bit_num bits.
		// for example, bit_num = 1, bit_cnt = 9, means 1-9 has 1 bit only.
		// use long long to avoid overflow
		long long bit_num = 1, bit_cnt = 9, base = 1;
		while (n > bit_num * bit_cnt) {
			n -= bit_num * bit_cnt;
			bit_num++;
			bit_cnt *= 10;
			base *= 10;
		}
		// now we know the number we are looking for is the order th number with num_bit bits.
		long long order = (n - 1) / bit_num, bit = (n - 1) % bit_num;
		long long num = order + base;
		// calculate the bit we are interested in.
		for (int i = bit_num - 1 - bit; i > 0; --i) {
			num /= 10;
		}
		return num % 10;
	}
};