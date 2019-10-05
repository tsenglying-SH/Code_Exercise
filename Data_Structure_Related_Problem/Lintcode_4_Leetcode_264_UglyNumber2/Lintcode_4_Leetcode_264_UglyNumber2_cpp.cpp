// heap based method, time O(nlogn), space O(n)
class Solution {
public:
	int nthUglyNumber(int n) {
		priority_queue<long, vector<long>, greater<long>> pq;
		pq.push(1);
		long res = 0;
		for (int i = 0; i < n; ++i) {
			res = pq.top(); pq.pop();
			// deduplicate
			while (!pq.empty() && res == pq.top()) {
				pq.pop();
			}

			pq.push(res * 2);
			pq.push(res * 3);
			pq.push(res * 5);
		}

		return res;
	}
};

// dp based method, time O(n), space O(n)
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
