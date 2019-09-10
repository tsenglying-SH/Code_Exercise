/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/

// BFS Topological Template O(V + E), in fact, here order traversal will be better
class Solution {
public:
	/**
	* @param grid: a chessboard included 0 (false) and 1 (true)
	* @param source: a point
	* @param destination: a point
	* @return: the shortest path
	*/
	int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
		// write your code here
		// corner case: invalid grid
		if (grid.empty() || grid[0].empty()) {
			return -1;
		}

		int max_r = grid.size(), max_c = grid[0].size();
		int sr = source.x, sc = source.y, dr = destination.x, dc = destination.y;

		// corner case: invalid source or destination
		if (sr < 0 || sr >= max_r || dr < 0 || dr >= max_r || sc < 0 ||
			sc >= max_c || sr < 0 || sr >= max_r) {
			return -1;
		}

		// initialize the visited
		vector<vector<int>> visited(max_r, vector<int>(max_c, -1));
		visited[sr][sc] = 0;

		// initialize the queue
		queue<Point> Q; Q.push(source);

		// available movements
		vector<vector<int>> movements = { { 1, 2 },{ 1, -2 },{ -1, 2 },{ -1, -2 },{ 2, 1 },{ 2, -1 },{ -2, -1 },{ -2, 1 } };


		while (!Q.empty()) {
			Point node = Q.front(); Q.pop();

			if (node.x == destination.x && node.y == destination.y) {
				return visited[node.x][node.y];
			}

			for (auto movement : movements) {
				int dr = movement[0], dc = movement[1];
				int nr = node.x + dr, nc = node.y + dc;
				if (nr >= 0 && nr < max_r && nc >= 0 && nc < max_c && grid[nr][nc] != 1 && visited[nr][nc] == -1) {
					visited[nr][nc] = visited[node.x][node.y] + 1;
					Q.push(Point(nr, nc));
				}
			}
		}
		return -1;
	}
};