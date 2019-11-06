/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/


// Union Find!
class Solution {
public:
	/**
	* @param n: An integer
	* @param m: An integer
	* @param operators: an array of point
	* @return: an integer array
	*/
	vector<int> numIslands2(int n, int m, vector<Point> &operators) {
		// write your code here
		if (n <= 0 || m <= 0) return{};
		// initialize
		vector<int> parents(n * m, -1);
		int count = 0;
		vector<int> res;
		vector<int> dx = { 1, 0, -1, 0 }, dy = { 0, 1, 0, -1 };
		for (int i = 0; i < operators.size(); ++i) {
			// check if the operate is valid
			if (operators[i].x < 0 || operators[i].x >= n || operators[i].y < 0 || operators[i].y >= m) continue;
			int id = operators[i].x * m + operators[i].y;
			// if not a new point, do nothing
			if (parents[id] != -1) {
				res.push_back(count);
				continue;
			}
			// new point, initialize a new union first
			++count;
			parents[id] = id;
			// check its neighbours
			for (int j = 0; j < dx.size(); ++j) {
				int n_x = operators[i].x + dx[j], n_y = operators[i].y + dy[j];
				int n_id = n_x * m + n_y;
				// if the neighbour is invalid or it hasn't been a point yet, skip it
				if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m || parents[n_id] == -1) continue;
				// merge 2 different union if necessary, and update count
				int old = find(parents, id), new_ = find(parents, n_id);
				if (old != new_) {
					parents[old] = new_;
					count--;
				}
			}
			res.push_back(count);
		}
		return res;
	}

	// here union + path compression, important but easy to write !
	int find(vector<int> & p, int idx) {
		if (p[idx] != idx) p[idx] = find(p, p[idx]);
		return p[idx];
	}
};