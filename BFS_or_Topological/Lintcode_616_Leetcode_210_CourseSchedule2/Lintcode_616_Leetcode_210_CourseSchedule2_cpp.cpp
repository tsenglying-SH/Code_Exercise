// BFS Topological Template, Time O(V + E)
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		if (numCourses <= 0) { return{}; }

		// initialize graph and indegree
		vector<vector<int>> graph(numCourses);
		vector<int> indegree(numCourses, 0);

		// update graph and indegree
		for (auto prerequisite : prerequisites) {
			int post = prerequisite[0];
			int pre = prerequisite[1];

			graph[pre].push_back(post);
			indegree[post]++;
		}

		// build queue
		queue<int> Q;
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				Q.push(i);
			}
		}

		// initialize answer
		int count = 0;
		vector<int> order;

		// Start BFS
		while (!Q.empty()) {
			int tail = Q.front(); Q.pop();
			count++;
			order.push_back(tail);

			for (int head : graph[tail]) {
				indegree[head]--;
				if (indegree[head] == 0) {
					Q.push(head);
				}
			}
		}
		if (count == numCourses) { return order; }
		return{};
	}
};