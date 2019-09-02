// time O(log n), first keep doubling to bigger than target, then binary search it.

/**
* Definition of ArrayReader:
*
* class ArrayReader {
* public:
*     int get(int index) {
*          // return the number on given index,
*          // return 2147483647 if the index is invalid.
*     }
* };
*/
class Solution {
public:
	/*
	* @param reader: An instance of ArrayReader.
	* @param target: An integer
	* @return: An integer which is the first index of target.
	*/
	int searchBigSortedArray(ArrayReader * reader, int target) {
		// write your code here
		if (reader->get(0) == target) {
			return 0;
		}
		if (reader->get(0) >= 2147483647) {
			return -1;
		}

		int start = 0, end = 0;
		while (reader->get(end) < target) {
			end = end * 2 + 1;
		}
		cout << end << endl;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (reader->get(mid) >= target) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		cout << start << " " << end << endl;
		if (reader->get(start) == target) {
			return start;
		}
		else if (reader->get(end) == target) {
			return end;
		}
		return -1;
	}
};