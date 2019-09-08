// naive BFS using set, so slow
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) { return 0; }

		int count = 0;
		set<pair<int, int>> visited;
		for (int r = 0; r < grid.size(); r++) {
			for (int c = 0; c < grid[0].size(); c++) {
				if (grid[r][c] == '1' && visited.find(make_pair(r, c)) == visited.end()) {
					count++;
					bfs(grid, r, c, visited);
				}
			}
		}
		return count;
	}

	void bfs(vector<vector<char>> &grid, int r, int c, set<pair<int, int>> &visited) {
		visited.insert(make_pair(r, c));
		queue<pair<int, int>> Q; Q.push(make_pair(r, c));

		while (!Q.empty()) {
			pair<int, int> node = Q.front(); Q.pop();
			vector<pair<int, int>> directions = { make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1) };
			for (auto direction : directions) {
				int nr = node.first + direction.first;
				int nc = node.second + direction.second;
				if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()
					&& visited.find(make_pair(nr, nc)) == visited.end() && grid[nr][nc] == '1') {
					Q.push(make_pair(nr, nc));
					visited.insert(make_pair(nr, nc));
				}
			}
		}
	}
};

// tricky BFS, do the inplace edit
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int count = 0;
		for (int r = 0; r < grid.size(); r++) {
			for (int c = 0; c < grid[0].size(); c++) {
				if (grid[r][c] == '1') {
					count++;
					bfs(grid, r, c);
				}
			}
		}
		return count;
	}

	void bfs(vector<vector<char>> &grid, int r, int c) {
		grid[r][c] = '0';
		queue<pair<int, int>> Q; Q.push(make_pair(r, c));

		while (!Q.empty()) {
			pair<int, int> node = Q.front(); Q.pop();
			vector<pair<int, int>> directions = { make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1) };
			for (auto direction : directions) {
				int nr = node.first + direction.first;
				int nc = node.second + direction.second;
				if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
					Q.push(make_pair(nr, nc));
					grid[nr][nc] = '0';
				}
			}
		}
	}
};

// dfs , the quickest method here
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}

		int count = 0;
		for (int r = 0; r < grid.size(); r++) {
			for (int c = 0; c < grid[0].size(); c++) {
				if (grid[r][c] == '1') {
					count++;
					dfs(grid, r, c);
				}
			}
		}
		return count;
	}

	void dfs(vector<vector<char>> &grid, int r, int c) {
		if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
			return;
		}
		if (grid[r][c] == '0') {
			return;
		}

		grid[r][c] = '0';

		dfs(grid, r + 1, c);
		dfs(grid, r - 1, c);
		dfs(grid, r, c + 1);
		dfs(grid, r, c - 1);
	}
};