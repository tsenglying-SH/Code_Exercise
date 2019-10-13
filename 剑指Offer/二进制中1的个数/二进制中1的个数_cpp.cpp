// substract the last 1, time O(logn)
class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		while (n != 0) {
			++count;
			// subtract the last 1
			n -= n & -n;
		}
		return count;
	}
};

// right shift method, time O(logn), must take care abount negative number
class Solution {
public:
	int NumberOf1(int n) {
		int count = 0;
		// translate to uint or negative number can cause infinite loop
		unsigned int un = n;
		while (un != 0) {
			// if the first bit is 1, then +1
			count += un & 1;
			un >>= 1;
		}
		return count;
	}
};