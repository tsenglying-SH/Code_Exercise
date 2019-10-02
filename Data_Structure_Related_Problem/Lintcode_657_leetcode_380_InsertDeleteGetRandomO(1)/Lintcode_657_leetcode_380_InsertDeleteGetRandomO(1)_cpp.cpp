// hashtable + vector to achieve O(1)
class RandomizedSet {
private:
	// help insert and remove in O(1)
	unordered_map<int, int> val_idx;
	// help get Random in O(1)
	vector<int> vals;

public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		// when insert, hashtable, array all do the O(1) operation
		if (val_idx.count(val)) {
			return false;
		}
		val_idx[val] = vals.size();
		vals.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		// when remove, hashtable help array do the O(1) operation as well as itself
		if (!val_idx.count(val)) {
			return false;
		}
		vals[val_idx[val]] = vals.back();
		val_idx[vals.back()] = val_idx[val];
		val_idx.erase(val);
		vals.pop_back();
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		// get Random in O(1) via array
		if (vals.empty()) {
			return 0;
		}
		return vals[rand() % vals.size()];
	}
};

