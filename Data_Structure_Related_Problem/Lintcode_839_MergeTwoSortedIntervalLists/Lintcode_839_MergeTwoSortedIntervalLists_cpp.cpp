// Just like Merge Two arrays, Time O(m + n)

/**
* Definition of Interval:
* classs Interval {
*     int start, end;
*     Interval(int start, int end) {
*         this->start = start;
*         this->end = end;
*     }
* }
*/

class Solution {
public:
	/**
	* @param list1: one of the given list
	* @param list2: another list
	* @return: the new sorted list of interval
	*/
	vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
		// write your code here
		if (list1.empty()) {
			return list2;
		}
		if (list2.empty()) {
			return list1;
		}

		int m = list1.size(), n = list2.size(), i = 0, j = 0;
		vector<Interval> res;

		while (i < m  && j < n) {
			if (list1[i].start <= list2[j].start) {
				append_interval(res, list1[i++]);
			}
			else {
				append_interval(res, list2[j++]);
			}
		}

		while (i < m) {
			append_interval(res, list1[i++]);
		}

		while (j < n) {
			append_interval(res, list2[j++]);
		}

		return res;
	}

	void append_interval(vector<Interval> &res, Interval interval) {
		if (res.empty() || res.back().end < interval.start) {
			res.push_back(interval);
		}

		res.back().end = max(res.back().end, interval.end);
	}
};