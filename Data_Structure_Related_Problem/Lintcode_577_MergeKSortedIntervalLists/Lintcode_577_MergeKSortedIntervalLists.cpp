// heap based method, time O(nlogk), space O(k)
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

struct cmp {
	bool operator()(const vector<int> &a, const vector<int> &b) {
		int diff = a[0] - b[0];
		if (diff == 0) {
			diff = a[1] - b[1];
		}
		if (diff == 0) {
			diff = a[2] - b[2];
		}
		if (diff == 0) {
			diff = a[3] - b[3];
		}
		return diff > 0;
	}
};


class Solution {
public:
	/**
	* @param intervals: the given k sorted interval lists
	* @return:  the new sorted interval list
	*/
	vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
		// write your code here
		if (intervals.empty()) {
			return{};
		}
		priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
		vector<Interval> res;

		for (int i = 0; i < intervals.size(); ++i) {
			if (!intervals[i].empty()) {
				pq.push({ intervals[i][0].start, intervals[i][0].end, i, 0 });
			}
		}

		while (!pq.empty()) {
			int idx1 = pq.top()[2], idx2 = pq.top()[3]; pq.pop();
			append_interval(res, intervals[idx1][idx2]);
			if (idx2 + 1 < intervals[idx1].size()) {
				pq.push({ intervals[idx1][idx2 + 1].start, intervals[idx1][idx2 + 1].end, idx1, idx2 + 1 });
			}
		}

		return res;
	}

	void append_interval(vector<Interval> &interval_list, Interval interval) {
		if (interval_list.empty() || interval_list.back().end < interval.start) {
			interval_list.push_back(interval);
			return;
		}
		interval_list.back().end = max(interval_list.back().end, interval.end);
	}
};


// divide and conquer method, time O(nlogk), space O(2 * n / k)(merge2lists, we use extra space)
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
	* @param intervals: the given k sorted interval lists
	* @return:  the new sorted interval list
	*/
	vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
		// write your code here
		if (intervals.empty()) {
			return{};
		}

		int step = 1, amount = intervals.size();
		while (amount > step) {
			for (int i = 0; i + step < amount; i += 2 * step) {
				intervals[i] = merge2SortedIntervalLists(intervals[i], intervals[i + step]);
			}
			step *= 2;
		}

		return intervals[0];
	}

	vector<Interval> merge2SortedIntervalLists(vector<Interval> &list1, vector<Interval> &list2) {
		if (list1.empty()) {
			return list2;
		}
		if (list2.empty()) {
			return list1;
		}
		vector<Interval> res;
		int i = 0, j = 0, m = list1.size(), n = list2.size();
		while (i < m && j < n) {
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

	void append_interval(vector<Interval> &interval_list, Interval interval) {
		if (interval_list.empty() || interval_list.back().end < interval.start) {
			interval_list.push_back(interval);
			return;
		}

		interval_list.back().end = max(interval_list.back().end, interval.end);
	}
};