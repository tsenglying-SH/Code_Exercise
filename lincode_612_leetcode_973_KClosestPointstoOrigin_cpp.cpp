//Priority Queue Based Method
/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/
Point global_origin;
long long distance(const Point &a, const Point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
struct compare {
	bool operator() (const Point &a, const Point &b) const {
		int diff = distance(a, global_origin) - distance(b, global_origin);
		if (diff == 0) {
			diff = a.x - b.x;
		}
		if (diff == 0) {
			diff = a.y - b.y;
		}
		return diff < 0;
	}
};


class Solution {
public:
	/**
	* @param points: a list of points
	* @param origin: a point
	* @param k: An integer
	* @return: the k closest points
	*/
	vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
		// write your code here
		global_origin = Point(origin.x, origin.y);
		priority_queue<Point, vector<Point>, compare> pq;

		for (int i = 0; i < points.size(); i++) {
			pq.push(points[i]);
			if (pq.size() > k) {
				pq.pop();
			}
		}
		vector<Point> res;
		while (pq.size() > 0) {
			res.push_back(pq.top());
			pq.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};





// Quick Selection
class Solution {

public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<vector<int>> result;
		partition(points, K, 0, points.size() - 1, result);
		return result;
	}

	int distance(const vector<int> &point) {
		return point[0] * point[0] + point[1] * point[1];
	}

	void partition(vector<vector<int>>& points, int K, int start, int end, vector<vector<int>> &result) {
		if (start > end) {
			return;
		}
		if (start == end && K == 1) {
			result.push_back(points[start]);
			return;
		}

		int l = start, r = end;
		int mid = l + (r - l) / 2;
		vector<int> pivot = points[mid];

		while (l <= r) {
			while (l <= r && distance(points[l]) < distance(pivot)) {
				l++;
			}
			while (l <= r && distance(points[r]) > distance(pivot)) {
				r--;
			}
			if (l <= r) {
				swap(points[l], points[r]);
				l++;
				r--;
			}
		}

		if (start + K - 1 <= r) {
			partition(points, K, start, r, result);
			return;
		}
		else if (start + K - 1 >= l) {
			result.insert(result.end(), points.begin() + start, points.begin() + l);
			partition(points, K - l + start, l, end, result);
			return;
		}
		else {
			result.insert(result.end(), points.begin() + start, points.begin() + l);
			return;
		}
	}
};