// BFS£¬looks simple, but took me so much time
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> neighbors;

Node() {}

Node(int _val, vector<Node*> _neighbors) {
val = _val;
neighbors = _neighbors;
}
};
*/
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr) { return nullptr; }
		// ensure node is saved in dict before joining the queue
		unordered_map<Node*, Node*> old_to_new;
		old_to_new[node] = new Node(node->val, {});
		queue<Node *> Q; Q.push(node);

		while (!Q.empty()) {
			Node* old_node = Q.front(); Q.pop();

			// link the neighbors to new_node
			for (auto old_neighbor : old_node->neighbors) {
				// if old_neighbor hasn't been visited yet, create a new node for it and link it to new node
				if (old_to_new.find(old_neighbor) == old_to_new.end()) {
					Node* new_neighbor = new Node(old_neighbor->val, {});
					// ensure node is saved in dict before joining the queue
					old_to_new[old_neighbor] = new_neighbor;
					old_to_new[old_node]->neighbors.push_back(new_neighbor);
					Q.push(old_neighbor);
				}
				else {
					old_to_new[old_node]->neighbors.push_back(old_to_new[old_neighbor]);
				}
			}
		}
		return old_to_new[node];
	}
};


// Just change the queue in to Stack, then it's iteration version DFS
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> neighbors;

Node() {}

Node(int _val, vector<Node*> _neighbors) {
val = _val;
neighbors = _neighbors;
}
};
*/
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr) { return nullptr; }

		unordered_map<Node*, Node*> old_to_new;
		old_to_new[node] = new Node(node->val, {});
		stack<Node *> S; S.push(node);

		while (!S.empty()) {
			Node* old_node = S.top(); S.pop();

			// link the neighbors to new_node
			for (auto old_neighbor : old_node->neighbors) {
				// if old_neighbor hasn't been visited yet, create a new node for it and link it to new node
				if (old_to_new.find(old_neighbor) == old_to_new.end()) {
					Node* new_neighbor = new Node(old_neighbor->val, {});
					old_to_new[old_neighbor] = new_neighbor;
					old_to_new[old_node]->neighbors.push_back(new_neighbor);
					S.push(old_neighbor);
				}
				else {
					old_to_new[old_node]->neighbors.push_back(old_to_new[old_neighbor]);
				}
			}
		}
		return old_to_new[node];
	}
};
// Tricky recursive DFS, during interview, had better use iteration version.
/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> neighbors;

Node() {}

Node(int _val, vector<Node*> _neighbors) {
val = _val;
neighbors = _neighbors;
}
};
*/
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr) { return nullptr; }

		unordered_map<Node*, Node*> old_new;
		Node* new_node = new Node(node->val, {});
		old_new[node] = new_node;
		dfs(node, old_new);
		return old_new[node];
	}

	void dfs(Node* node, unordered_map<Node*, Node*> &old_new) {
		if (node == nullptr) { return; }
		for (auto neighbor : node->neighbors) {
			if (old_new.find(neighbor) == old_new.end()) {
				old_new[neighbor] = new Node(neighbor->val, {});
				dfs(neighbor, old_new);
			}
			old_new[node]->neighbors.push_back(old_new[neighbor]);
		}
	}
};