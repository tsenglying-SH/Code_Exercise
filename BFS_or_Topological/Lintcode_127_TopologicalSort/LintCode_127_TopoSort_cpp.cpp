// classical BFS topological template
/**
* Definition for Directed graph.
* struct DirectedGraphNode {
*     int label;
*     vector<DirectedGraphNode *> neighbors;
*     DirectedGraphNode(int x) : label(x) {};
* };
*/

class Solution {
public:
	/*
	* @param graph: A list of Directed graph node
	* @return: Any topological order for the given graph.
	*/
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
		// write your code here
		if (graph.size() == 0) {
			return{};
		}

		unordered_map<DirectedGraphNode*, int> indegree;
		for (auto node : graph) {
			indegree[node] = 0;
		}

		for (auto node : graph) {
			for (auto head : node->neighbors) {
				indegree[head]++;
			}
		}


		queue<DirectedGraphNode*> Q;
		for (auto node : indegree) {
			if (node.second == 0) {
				Q.push(node.first);
			}
		}
		vector<DirectedGraphNode*> order;

		while (!Q.empty()) {
			DirectedGraphNode* tail = Q.front(); Q.pop();
			order.push_back(tail);

			for (auto head : tail->neighbors) {
				indegree[head] -= 1;
				if (indegree[head] == 0) {
					Q.push(head);
				}
			}
		}
		return order;
	}
};

// Change queue into stack , that's DFS iteration version
/**
* Definition for Directed graph.
* struct DirectedGraphNode {
*     int label;
*     vector<DirectedGraphNode *> neighbors;
*     DirectedGraphNode(int x) : label(x) {};
* };
*/

class Solution {
public:
	/*
	* @param graph: A list of Directed graph node
	* @return: Any topological order for the given graph.
	*/
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
		// write your code here
		if (graph.size() == 0) {
			return{};
		}

		unordered_map<DirectedGraphNode*, int> indegree;
		for (auto node : graph) {
			indegree[node] = 0;
		}

		for (auto node : graph) {
			for (auto head : node->neighbors) {
				indegree[head]++;
			}
		}


		stack<DirectedGraphNode*> S;
		for (auto node : indegree) {
			if (node.second == 0) {
				S.push(node.first);
			}
		}
		vector<DirectedGraphNode*> order;

		while (!S.empty()) {
			DirectedGraphNode* tail = S.top(); S.pop();
			order.push_back(tail);

			for (auto head : tail->neighbors) {
				indegree[head] -= 1;
				if (indegree[head] == 0) {
					S.push(head);
				}
			}
		}
		return order;
	}
};

// Recursive DFS which does not care about cycle.
/**
* Definition for Directed graph.
* struct DirectedGraphNode {
*     int label;
*     vector<DirectedGraphNode *> neighbors;
*     DirectedGraphNode(int x) : label(x) {};
* };
*/

class Solution {
public:
	/*
	* @param graph: A list of Directed graph node
	* @return: Any topological order for the given graph.
	*/
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
		// write your code here
		if (graph.empty()) { return{}; }

		unordered_set<DirectedGraphNode*> visited;
		vector<DirectedGraphNode*> order;
		for (auto node : graph) {
			if (visited.find(node) == visited.end()) {
				dfs(node, graph, visited, order);
			}
		}
		reverse(order.rbegin(), order.rend());
		return order;
	}

	void dfs(DirectedGraphNode* node, vector<DirectedGraphNode*>& graph,
		unordered_set<DirectedGraphNode*> & visited, vector<DirectedGraphNode*> & order) {
		if (node == nullptr) { return; }
		visited.insert(node);
		for (auto neighbor : node->neighbors) {
			if (visited.find(neighbor) == visited.end()) {
				dfs(neighbor, graph, visited, order);
			}
		}
		order.push_back(node);
	}
};

// Recursive DFS which care about cycle.
/**
* Definition for Directed graph.
* struct DirectedGraphNode {
*     int label;
*     vector<DirectedGraphNode *> neighbors;
*     DirectedGraphNode(int x) : label(x) {};
* };
*/

class Solution {
public:
	/*
	* @param graph: A list of Directed graph node
	* @return: Any topological order for the given graph.
	*/
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
		// write your code here
		if (graph.empty()) { return{}; }

		unordered_map<DirectedGraphNode*, int> visited_st;
		for (auto tail : graph) {
			visited_st[tail] = 0;
		}


		vector<DirectedGraphNode*> order;
		for (auto tail : graph) {
			if (visited_st[tail] == 0 && !acyclic(tail, graph, visited_st, order)) {
				return{};
			}
		}
		// here  remember reverse it
		reverse(order.rbegin(), order.rend());
		return order;
	}

	bool acyclic(DirectedGraphNode* tail, vector<DirectedGraphNode*> &graph,
		unordered_map<DirectedGraphNode*, int> &visited_st, vector<DirectedGraphNode*> &order) {
		if (visited_st[tail] == -1) {
			return false;
		}

		if (visited_st[tail] == 1) {
			return true;
		}

		visited_st[tail] = -1;
		for (auto neighbor : tail->neighbors) {
			if (!acyclic(neighbor, graph, visited_st, order)) {
				return false;
			}
		}

		visited_st[tail] = 1;
		order.push_back(tail);
		return true;
	}
};