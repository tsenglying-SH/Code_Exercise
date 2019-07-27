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
		vector<Interval> res;
		int i = 0, j = 0;
		while (i < list1.size() && j < list2.size()) {
			if (list1[i].start <= list2[j].start) {
				push_back_int(res, list1[i]);
				i++;
			}
			else {
				push_back_int(res, list2[j]);
				j++;
			}
		}
		while (i < list1.size()) {
			push_back_int(res, list1[i]);
			i++;
		}
		while (j < list2.size()) {
			push_back_int(res, list2[j]);
			j++;
		}

		return res;

	}

	void push_back_int(vector<Interval> &res, const Interval &interval) {
		if (res.size() == 0 || res.back().end < interval.start) {
			res.push_back(interval);
		}

		if (res.back().end >= interval.start) {
			Interval new_interv(res.back().start, max(res.back().end, interval.end));
			res.pop_back();
			res.push_back(new_interv);
		}
	}
};