class LRUCache {
private:
	size_t m_capacity;
	unordered_map<int, list<pair<int, int>>::iterator> key_to_node;
	list<pair<int, int>> m_list;
public:
	LRUCache(int capacity) : m_capacity(capacity) {

	}

	int get(int key) {
		// write your code here
		if (key_to_node.find(key) == key_to_node.end()) {
			return -1;
		}
		m_list.splice(m_list.begin(), m_list, key_to_node[key]);
		return key_to_node[key]->second;
	}

	void put(int key, int value) {
		// write your code here
		if (key_to_node.find(key) != key_to_node.end()) {
			m_list.splice(m_list.begin(), m_list, key_to_node[key]);
			key_to_node[key]->second = value;
			return;
		}

		if (key_to_node.size() == m_capacity) {
			int key_to_delete = m_list.back().first;
			m_list.pop_back();
			key_to_node.erase(key_to_delete);
		}

		m_list.emplace_front(key, value);
		key_to_node[key] = m_list.begin();

	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/