// Recursive dfs, O(rows * cols)
class Solution {
private:
	int count;
public:
	int movingCount(int threshold, int rows, int cols) {
		if (rows <= 0 || cols <= 0 || threshold < 0) {
			return 0;
		}
		count = 0;
		vector<vector<bool>> recorded(rows, vector<bool>(cols, false));
		dfs(0, 0, threshold, rows, cols, recorded);
		return count;
	}
	void dfs(int x, int y, int threshold, int rows, int cols, vector<vector<bool>> &recorded) {
		if (!recorded[x][y]) {
			recorded[x][y] = true;
			count++;
		}

		vector<int> dx = { 1, 0, -1, 0 };
		vector<int> dy = { 0, 1, 0, -1 };
		for (int i = 0; i < dx.size(); ++i) {
			int new_x = x + dx[i], new_y = y + dy[i];
			if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols &&
				cal_sum(new_x, new_y) <= threshold && !recorded[new_x][new_y]) {
				dfs(new_x, new_y, threshold, rows, cols, recorded);
			}
		}
	}

	int cal_sum(int x, int y) {
		int res = 0;
		while (x) {
			res += x % 10;
			x /= 10;
		}
		while (y) {
			res += y % 10;
			y /= 10;
		}
		return res;
	}
};

// BFS, time O(rows * cols)
class Solution {
public:
	int movingCount(int threshold, int rows, int cols) {
		if (rows <= 0 || cols <= 0 || threshold < 0) {
			return 0;
		}
		int count = 0;
		queue<vector<int>> Q;
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));

		Q.push({ 0, 0 });
		count++;
		visited[0][0] = true;
		vector<int> dx = { 1, 0, -1, 0 };
		vector<int> dy = { 0, 1, 0, -1 };

		while (!Q.empty()) {
			vector<int> x_y = Q.front(); Q.pop();

			for (int i = 0; i < dx.size(); ++i) {
				int new_x = x_y[0] + dx[i], new_y = x_y[1] + dy[i];
				if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols &&
					cal_sum(new_x, new_y) <= threshold && !visited[new_x][new_y]) {
					count++;
					visited[new_x][new_y] = true;
					Q.push({ new_x, new_y });
				}
			}
		}
		return count;
	}

	int cal_sum(int x, int y) {
		int res = 0;
		while (x) {
			res += x % 10;
			x /= 10;
		}
		while (y) {
			res += y % 10;
			y /= 10;
		}
		return res;
	}
};

// change the queue of the BFS to stack, then it's iterative DFS, time O(rows * cols)
class Solution {
public:
	int movingCount(int threshold, int rows, int cols) {
		if (rows <= 0 || cols <= 0 || threshold < 0) {
			return 0;
		}
		int count = 0;
		stack<vector<int>> S;
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));

		S.push({ 0, 0 });
		count++;
		visited[0][0] = true;
		vector<int> dx = { 1, 0, -1, 0 };
		vector<int> dy = { 0, 1, 0, -1 };

		while (!S.empty()) {
			vector<int> x_y = S.top(); S.pop();

			for (int i = 0; i < dx.size(); ++i) {
				int new_x = x_y[0] + dx[i], new_y = x_y[1] + dy[i];
				if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols &&
					cal_sum(new_x, new_y) <= threshold && !visited[new_x][new_y]) {
					count++;
					visited[new_x][new_y] = true;
					S.push({ new_x, new_y });
				}
			}
		}
		return count;
	}

	int cal_sum(int x, int y) {
		int res = 0;
		while (x) {
			res += x % 10;
			x /= 10;
		}
		while (y) {
			res += y % 10;
			y /= 10;
		}
		return res;
	}
};