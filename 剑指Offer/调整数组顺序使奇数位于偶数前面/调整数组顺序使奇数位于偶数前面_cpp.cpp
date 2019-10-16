// two pointer in the same direction, time O(n) 
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty()) {
			return;
		}

		int i = 0, j = 0;
		while (j < array.size()) {
			if (array[j] & 1) {
				swap(array[i++], array[j++]);
			}
			else {
				j++;
			}
		}

	}
};

// reusable version 1
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		solver(array, isOdd);
	}

	void solver(vector<int> &array, bool(*func)(int)) {
		if (array.empty()) {
			return;
		}

		int i = 0, j = 0;
		while (j < array.size()) {
			if (func(array[j])) {
				swap(array[i++], array[j++]);
			}
			else {
				j++;
			}
		}
	}
	// here use static or write these function out of the class, or you will meet some error
	static bool isOdd(int x) {
		return x & 1;
	}
	static bool x3(int x) {
		return x % 3 == 0;
	}
};

// two pointer in different direction, just like partition template in quick sort!, time O(n)
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty()) {
			return;
		}

		int i = 0, j = array.size() - 1;
		while (i <= j) {
			while (i <= j && (array[i] & 1)) {
				i++;
			}
			while (i <= j && !(array[j] & 1)) {
				j--;
			}
			if (i <= j) {
				swap(array[i++], array[j--]);
			}
		}
	}
};
// reusable version 2
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		solver(array, isOdd);
	}

	void solver(vector<int> &array, bool(*func)(int)) {
		if (array.empty()) {
			return;
		}

		int i = 0, j = array.size() - 1;
		while (i <= j) {
			while (i <= j && func(array[i])) {
				i++;
			}
			while (i <= j && !func(array[j])) {
				j--;
			}
			if (i <= j) {
				swap(array[i++], array[j--]);
			}
		}
	}
	// here use static or write these function out of the class, or you will meet some error
	static bool isOdd(int x) {
		return x & 1;
	}
	static bool x3(int x) {
		return x % 3 == 0;
	}

};