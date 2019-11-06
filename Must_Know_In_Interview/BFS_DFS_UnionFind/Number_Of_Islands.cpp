// BFS
class Solution {
private:
	int count = 0;
	void bfs(vector<vector<char>> &grid, int x, int y) {
		if (grid.empty() || grid[0].empty()) return;
		int m = grid.size(), n = grid[0].size();
		queue<pair<int, int>> Q; Q.push({ x, y });
		grid[x][y] = '0';
		vector<int> dx = { 1, 0, -1, 0 };
		vector<int> dy = { 0, 1, 0, -1 };
		while (!Q.empty()) {
			auto x_y = Q.front(); Q.pop();
			for (int i = 0; i < dx.size(); ++i) {
				int new_x = x_y.first + dx[i], new_y = x_y.second + dy[i];
				if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == '0') continue;
				grid[new_x][new_y] = '0';
				Q.push({ new_x, new_y });
			}
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					++count;
					bfs(grid, i, j);
				}
			}
		}
		return count;
	}
};

// DFS, just change the queue into stack
class Solution {
private:
	int count = 0;
	void dfs(vector<vector<char>> &grid, int x, int y) {
		if (grid.empty() || grid[0].empty()) return;
		int m = grid.size(), n = grid[0].size();
		stack<pair<int, int>> S; S.push({ x, y });
		grid[x][y] = '0';
		vector<int> dx = { 1, 0, -1, 0 };
		vector<int> dy = { 0, 1, 0, -1 };
		while (!S.empty()) {
			auto x_y = S.top(); S.pop();
			for (int i = 0; i < dx.size(); ++i) {
				int new_x = x_y.first + dx[i], new_y = x_y.second + dy[i];
				if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] == '0') continue;
				grid[new_x][new_y] = '0';
				S.push({ new_x, new_y });
			}
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					++count;
					dfs(grid, i, j);
				}
			}
		}
		return count;
	}
};

// Recursion DFS
class Solution {
private:
	int count = 0;
	void dfs(vector<vector<char>> &grid, int x, int y) {
		if (grid.empty() || grid[0].empty()) return;
		int m = grid.size(), n = grid[0].size();
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1') return;
		grid[x][y] = '0';

		dfs(grid, x, y - 1);
		dfs(grid, x + 1, y);
		dfs(grid, x, y + 1);
		dfs(grid, x - 1, y);
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					++count;
					dfs(grid, i, j);
				}
			}
		}
		return count;
	}
};