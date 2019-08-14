class Node {
public:
	int e, a_n, p;
	Node(int element, int array_num, int pos) : e(element), a_n(array_num), p(pos) {};
};

struct cmp {
	bool operator()(Node &a, Node &b) {
		int diff = a.e - b.e;
		if (diff == 0) {
			diff = a.a_n - b.a_n;
		}
		if (diff == 0) {
			diff = a.p - b.p;
		}
		return diff > 0;
	}
};



class Solution {
public:
	/**
	* @param arrays: k sorted integer arrays
	* @return: a sorted array
	*/
	vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
		// write your code here
		vector<int> res;
		priority_queue<Node, vector<Node>, cmp> heap;


		for (int i = 0; i < arrays.size(); i++) {
			if (arrays[i].empty()) {
				continue;
			}
			heap.push(Node(arrays[i][0], i, 0));
		}

		while (heap.size() > 0) {
			Node top_node = heap.top(); heap.pop();
			if (top_node.p + 1 < arrays[top_node.a_n].size()) {
				heap.push(Node(arrays[top_node.a_n][top_node.p + 1], top_node.a_n, top_node.p + 1));
			}
			res.push_back(top_node.e);
		}
		return res;
	}
};
