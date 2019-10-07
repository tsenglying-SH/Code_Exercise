struct Node {
	int k;
	int val;
	Node *prev, *next;
	Node(int key, int value) : k(key), val(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
	int cap = 0;
	Node *tail = new Node(0, 0), *head = new Node(0, 0);
	unordered_map<int, Node*> key_to_node;

	void move_to_head(Node *node) {
		node->next = head->next;
		node->prev = head;
		head->next = node;
		node->next->prev = node;
	}

public:
	LRUCache(int capacity) {
		cap = capacity;
		tail->prev = head;
		head->next = tail;
	}

	int get(int key) {
		if (key_to_node.find(key) == key_to_node.end()) {
			return -1;
		}
		Node *node = key_to_node[key];
		node->prev->next = node->next;
		node->next->prev = node->prev;
		move_to_head(node);
		return node->val;
	}

	void put(int key, int value) {
		if (key_to_node.count(key)) {
			Node *node = key_to_node[key];
			node->prev->next = node->next;
			node->next->prev = node->prev;
			move_to_head(node);
			node->val = value;
		}
		else {
			Node *node = new Node(key, value);
			move_to_head(node);
			key_to_node[key] = node;
		}

		if (key_to_node.size() > cap) {
			Node *to_remove = tail->prev;
			to_remove->prev->next = tail;
			tail->prev = to_remove->prev;

			key_to_node.erase(to_remove->k);
		}
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/