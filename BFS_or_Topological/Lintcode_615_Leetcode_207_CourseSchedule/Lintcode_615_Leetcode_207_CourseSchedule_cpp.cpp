//basic BFS topological, time O(V + E)
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> indegree(numCourses, 0);

		for (auto post_pre : prerequisites) {
			int post = post_pre[0];
			int pre = post_pre[1];

			graph[pre].push_back(post);
			indegree[post]++;
		}

		queue<int> Q;
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				Q.push(i);
			}
		}

		int count = 0;
		while (!Q.empty()) {
			int tail = Q.front(); Q.pop();
			count++;

			for (int head : graph[tail]) {
				indegree[head]--;
				if (indegree[head] == 0) {
					Q.push(head);
				}
			}
		}
		return count == numCourses;
	}
};