// Lintcode solution, leetcode may be a little different.
// BFS to build graph and calculate the max_distance, DFS to search all path, time O(n^2 + n + 2^n * n)
class Solution {
public:
	/*
	* @param start: a string
	* @param end: a string
	* @param dict: a set of string
	* @return: a list of lists of string
	*/
	vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
		// write your code here
		dict.insert(end);

		queue<string> Q; Q.push(start);
		unordered_map<string, unordered_set<string>> graph;
		graph[start] = unordered_set<string>();
		unordered_map<string, int> dists;
		dists[start] = 0;
		int dist = 0;
		bool found = false;

		while (!Q.empty()) {
			int size = Q.size();
			dist++;
			unordered_set<string> used;
			for (int i = 0; i < size; i++) {
				string tail = Q.front(); Q.pop();
				used.insert(tail);
				if (tail == end) {
					found = true;
				}
				for (int j = 0; j < tail.size(); j++) {
					for (char c = 'a'; c <= 'z'; c++) {
						string head = tail;
						head[j] = c;
						if (head == tail) {
							continue;
						}
						if (dict.count(head)) {
							graph[tail].insert(head);
							if (!graph.count(head)) {
								graph[head] = unordered_set<string>();
							}
							if (!dists.count(head)) {
								dists[head] = dist;
								Q.push(head);
							}
						}
					}
				}
			}
			for (string used_word : used) {
				if (dict.count(used_word)) {
					dict.erase(used_word);
				}
			}
			if (found) {
				break;
			}
		}

		vector<vector<string>> res = {};
		vector<string> path = { start };
		dfs(dist - 1, 0, graph, dists, path, res, end);
		return res;
	}

	void dfs(int limit, int curr_dist, unordered_map<string, unordered_set<string>> &graph,
		unordered_map<string, int> &dists, vector<string> &path, vector<vector<string>> &res,
		const string &end) {
		if (curr_dist == limit) {
			if (path.back() == end) {
				res.push_back(path);
			}
			return;
		}
		string tail = path.back();
		for (string head : graph[tail]) {
			if (dists[tail] + 1 == dists[head]) {
				path.push_back(head);
				dfs(limit, curr_dist + 1, graph, dists, path, res, end);
				path.pop_back();
			}
		}
	}
};