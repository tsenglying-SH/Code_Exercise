// Mistakes are easy to make during building here graph and indegree here
// After finish the graph, indegree, do the classical topological sort and ensure the queue contains only 1 element
class Solution {
public:
	/**
	* @param org: a permutation of the integers from 1 to n
	* @param seqs: a list of sequences
	* @return: true if it can be reconstructed only one or false
	*/
	bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
		// write your code here
		unordered_map<int, unordered_set<int>> graph;
		unordered_map<int, int> indegree;

		for (auto seq : seqs) {
			for (int i = 0; i < seq.size(); i++) {
				graph[seq[i]] = unordered_set<int>();
				indegree[seq[i]] = 0;
			}
		}

		for (auto seq : seqs) {
			for (int j = 0; j < seq.size(); j++) {
				if (j < seq.size() - 1) {
					graph[seq[j]].insert(seq[j + 1]);
				}
			}
		}

		for (auto tail_heads : graph) {
			for (int head : tail_heads.second) {
				indegree[head]++;
			}
		}

		queue<int> Q;
		for (auto node : indegree) {
			if (indegree[node.first] == 0) {
				Q.push(node.first);
			}
		}

		vector<int> order;

		while (!Q.empty()) {
			if (Q.size() > 1) {
				return false;
			}

			int tail = Q.front(); Q.pop();
			order.push_back(tail);

			for (int head : graph[tail]) {
				indegree[head]--;
				if (indegree[head] == 0) {
					Q.push(head);
				}
			}
		}
		return order == org;
	}
};

// A tricky way, check the priority of the elements
class Solution {
public:
	/**
	* @param org: a permutation of the integers from 1 to n
	* @param seqs: a list of sequences
	* @return: true if it can be reconstructed only one or false
	*/
	bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
		// write your code here
		unordered_map<int, int> position;
		unordered_map<int, int> pre;
		for (int i = 0; i < org.size(); i++) {
			position[org[i]] = i;
		}

		for (auto seq : seqs) {
			for (int j = 0; j < seq.size(); j++) {
				// check whether there are some odd elements
				if (position.find(seq[j]) == position.end()) {
					return false;
				}

				// check the order
				if (j > 0 && position[seq[j]] <= position[seq[j - 1]]) {
					return false;
				}

				if (pre.find(seq[j]) == pre.end()) {
					pre[seq[j]] = j > 0 ? position[seq[j - 1]] : -1;
				}
				else {
					int tmp = j > 0 ? position[seq[j - 1]] : -1;
					pre[seq[j]] = max(pre[seq[j]], tmp);
				}
			}
		}

		for (int k = 0; k < org.size(); k++) {
			if (pre.find(org[k]) == pre.end() || pre[org[k]] != k - 1) {
				return false;
			}
		}
		return true;
	}
};