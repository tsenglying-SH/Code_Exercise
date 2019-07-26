class Solution {
public:
	/**
	* @param n: An integer
	* @return: return a  integer as description.
	*/
	int nthUglyNumber(int n) {
		// write your code here
		if (n <= 0) { return 0; }
		vector<int> ugly_list(1, 1);
		int p2 = 0, p3 = 0, p5 = 0;
		while (ugly_list.size() < n) {
			ugly_list.push_back(min(ugly_list[p2] * 2, min(ugly_list[p3] * 3, ugly_list[p5] * 5)));
			if (ugly_list.back() == ugly_list[p2] * 2) { p2++; }
			if (ugly_list.back() == ugly_list[p3] * 3) { p3++; }
			if (ugly_list.back() == ugly_list[p5] * 5) { p5++; }
		}
		return ugly_list.back();
	}
};
