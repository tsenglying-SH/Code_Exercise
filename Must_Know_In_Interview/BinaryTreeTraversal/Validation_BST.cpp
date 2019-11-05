// just traversal it and check, time O(n)
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode *> stk;
		TreeNode *last = nullptr;

		while (true) {
			while (root) stk.push(root), root = root->left;
			if (stk.empty()) break;
			root = stk.top(); stk.pop();
			if (last && last->val >= root->val) return false;
			last = root;
			root = root->right;
		}
		return true;
	}
};


// a Recursion method, time O(n)
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		return check(root, LLONG_MIN, LLONG_MAX);
	}

	bool check(TreeNode *node, long low_bound, long up_bound) {
		if (!node) return true;

		if (node->val <= low_bound || node->val >= up_bound) return false;

		if (!check(node->left, low_bound, node->val)) return false;
		if (!check(node->right, node->val, up_bound)) return false;

		return true;
	}
};