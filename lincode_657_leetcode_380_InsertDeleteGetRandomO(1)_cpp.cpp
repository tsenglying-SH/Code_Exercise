class RandomizedSet {
private:
	unordered_map <int, int> dict;
	vector<int> vec;
public:
	RandomizedSet() {
		// do intialization if necessary

	}

	/*
	* @param val: a value to the set
	* @return: true if the set did not already contain the specified element or false
	*/
	bool insert(int val) {
		// write your code here
		if (dict.find(val) != dict.end()) { return false; }

		vec.push_back(val);
		dict[val] = vec.size() - 1;
		return true;
	}

	/*
	* @param val: a value from the set
	* @return: true if the set contained the specified element or false
	*/
	bool remove(int val) {
		// write your code here
		if (dict.find(val) == dict.end()) { return false; }

		vec[dict[val]] = vec[vec.size() - 1];
		dict[vec[vec.size() - 1]] = dict[val];
		vec.pop_back();
		dict.erase(val);
		return true;
	}

	/*
	* @return: Get a random element from the set
	*/
	int getRandom() {
		// write your code here
		return vec[rand() % vec.size()];
	}
};
