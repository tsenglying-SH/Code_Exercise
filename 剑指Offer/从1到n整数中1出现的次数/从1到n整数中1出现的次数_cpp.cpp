// time O(logn), really tricky, count bit by bit
class Solution {
public:
	int numberOf1Between1AndN_Solution(int n) {
		if (n < 1) return 0;
		int count = 0, factor = 1;
		while (n / factor != 0) {
			int cur_bit = (n / factor) % 10;
			int left = n / (factor * 10);
			int right = n % factor;

			if (cur_bit == 0) {
				count += left * factor;
			}
			else if (cur_bit == 1) {
				count += left * factor + right + 1;
			}
			else {
				count += (left + 1) * factor;
			}
			factor *= 10;
		}
		return count;
	}
};