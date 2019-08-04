class NumArray {
private:
	vector<int> array;
	int n;
	vector<int> bit;

	inline int lowbit(int x) {
		return x & (-x);
	}

	void add(int idx, int val) {
		idx++;
		while (idx <= n) {
			bit[idx] += val;
			idx += lowbit(idx);
		}
	}

	int sum(int idx) {
		idx++;
		int res = 0;
		while (idx > 0) {
			res += bit[idx];
			idx -= lowbit(idx);
		}
		return res;
	}

public:
	NumArray(vector<int>& nums) :array(nums), n(nums.size()), bit(n + 1, 0) {
		for (int i = 0; i < n; i++) {
			add(i, array[i]);
		}
	}

	void update(int i, int val) {
		add(i, val - array[i]);
		array[i] = val;
	}

	int sumRange(int i, int j) {
		return sum(j) - sum(i - 1);
	}
};
