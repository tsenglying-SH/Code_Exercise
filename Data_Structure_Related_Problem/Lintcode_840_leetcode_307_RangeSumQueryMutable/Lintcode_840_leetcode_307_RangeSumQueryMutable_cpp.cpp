// Binary Indexed Tree, build O(n), cal sum/update O(logn)
class NumArray {
private:
	vector<int> origin;
	int size = 0;
	vector<int> sum_arr;

	int lowerbit(int x) {
		return x & (-x);
	}

	void add(int i, int val) {
		i += 1;
		while (i <= size) {
			sum_arr[i] += val;
			i += lowerbit(i);
		}
	}

	int cal_sum(int i) {
		i += 1;
		int res = 0;
		while (i > 0) {
			res += sum_arr[i];
			i -= lowerbit(i);
		}
		return res;
	}

public:
	NumArray(vector<int>& nums) {
		origin = nums;
		size = nums.size();
		sum_arr = vector<int>(size + 1, 0);
		// O(nlogn) build via add;
		// for (int i = 0; i < size; ++i){
		//     add(i, nums[i]);
		// }

		// O(n) build
		// first write the nums[0]~nums[size - 1] to the sum_arr[1]~sum_arr[size]
		for (int i = 1; i <= size; ++i) {
			sum_arr[i] = nums[i - 1];
		}
		// then traverse i and update sum_arr[j], j = i + (i & (-i))
		for (int i = 1; i <= size; ++i) {
			int j = i + lowerbit(i);
			if (j <= size) {
				sum_arr[j] += sum_arr[i];
			}
		}
	}

	void update(int i, int val) {
		add(i, val - origin[i]);
		origin[i] = val;
	}

	int sumRange(int i, int j) {
		return cal_sum(j) - cal_sum(i - 1);
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray* obj = new NumArray(nums);
* obj->update(i,val);
* int param_2 = obj->sumRange(i,j);
*/

// Segment Tree via TreeNode, build O(n), update/sum O(logn)
struct SegTreeNode {
	int start, end, total;
	SegTreeNode *left, *right;
	SegTreeNode(int s, int e, int t = 0) : start(s), end(e), total(t), left(nullptr), right(nullptr) {}
};

class SegTree {
public:
	SegTreeNode *root = nullptr;
	SegTree(vector<int> &nums) {
		root = buildTree(0, nums.size() - 1, nums);
	}
	SegTreeNode * buildTree(int start, int end, const vector<int> &nums) {
		if (start > end) { return nullptr; }
		if (start == end) {
			SegTreeNode * node = new SegTreeNode(start, end, nums[start]);
			return node;
		}
		SegTreeNode *node = new SegTreeNode(start, end, 0);
		int mid = node->start + (node->end - node->start) / 2;
		node->left = buildTree(start, mid, nums);
		node->right = buildTree(mid + 1, end, nums);
		if (node->left != nullptr) {
			node->total += node->left->total;
		}
		if (node->right != nullptr) {
			node->total += node->right->total;
		}
		return node;
	}

	void update(SegTreeNode *node, int i, int val) {
		if (node->start == i && node->end == i) {
			node->total = val;
			return;
		}
		int mid = node->start + (node->end - node->start) / 2;
		if (i <= mid) {
			update(node->left, i, val);
		}
		else {
			update(node->right, i, val);
		}
		node->total = 0;
		if (node->left != nullptr) {
			node->total += node->left->total;
		}
		if (node->right != nullptr) {
			node->total += node->right->total;
		}
	}

	int sumRange(SegTreeNode *node, int i, int j) {
		if (node == nullptr) {
			return 0;
		}
		if (i < node->start || i > node->end || j < node->start || j > node->end) {
			return 0;
		}
		if (node->start == i && node->end == j) {
			return node->total;
		}
		int mid = node->start + (node->end - node->start) / 2;
		if (j <= mid) {
			return sumRange(node->left, i, j);
		}
		else if (i > mid) {
			return sumRange(node->right, i, j);
		}
		else {
			return sumRange(node->left, i, mid) + sumRange(node->right, mid + 1, j);
		}
	}
};


// Segment Tree via Array, build O(n), update/sum O(logn)
class NumArray {
private:
	SegTree tree;
public:
	NumArray(vector<int>& nums) :tree(nums) {

	}

	void update(int i, int val) {
		tree.update(tree.root, i, val);
	}

	int sumRange(int i, int j) {
		return tree.sumRange(tree.root, i, j);
	}
};

class NumArray {
private:
	int size;
	vector<int> tree_arr;
public:
	NumArray(vector<int>& nums) : size(nums.size()), tree_arr(2 * size, 0) {
		// write the nums to the tree_arr[size] ~ tree_arr[2 * size - 1]
		for (int i = size; i < 2 * size; ++i) {
			tree_arr[i] = nums[i - size];
		}
		// # i's sons are 2i, 2i + 1
		for (int i = size - 1; i > 0; --i) {
			tree_arr[i] = tree_arr[i << 1] + tree_arr[i << 1 | 1];
		}
	}

	void update(int i, int val) {
		i += size;
		tree_arr[i] = val;
		while (i > 0) {
            // if i is odd, left is i - 1, if i is even, right is i + 1
			tree_arr[i >> 1] = tree_arr[i] + tree_arr[i ^ 1];
			i >>= 1;
		}
	}

	int sumRange(int i, int j) {
		i += size;
		j += size;
		int res = 0;
		while (i <= j) {
			if (i & 1) {
				res += tree_arr[i++];
			}
			i >>= 1;
			if (!(j & 1)) {
				res += tree_arr[j--];
			}
			j >>= 1;
		}
		return res;
	}
};