/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// Recursion method, time O(n), space O(n)
class Solution {
private:
	vector<int> res;
public:
	vector<int> postorderTraversal(TreeNode* root) {
		postorder(root);
		return res;
	}

	void postorder(TreeNode *root) {
		if (!root) return;
		postorder(root->left);
		postorder(root->right);
		res.push_back(root->val);
	}
};

// iterative method 1, do the preorder traversal and reverse it.. not good
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root) return{};
		stack<TreeNode *> stk;
		vector<int> res;
		TreeNode *node = root;
		while (true) {
			while (node) {
				res.push_back(node->val);
				if (node->left) stk.push(node->left);
				node = node->right;
			}
			if (stk.empty()) break;
			node = stk.top(); stk.pop();
		}

		return vector<int>(res.rbegin(), res.rend());
	}
};

// iterative method according to postorder rules
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (!root) return{};
		stack<TreeNode *> stk;
		vector<int> res;
		TreeNode *last = nullptr, *node;
		while (root || !stk.empty()) {
			// traverse left first
			while (root) stk.push(root), root = root->left;
			node = stk.top();
			// no left sons more, traverse right if it hasn't been traverse
			if (node->right && node->right != last) root = node->right;
			// if left, right both traversed, record node
			else {
				res.push_back(node->val);
				last = node;
				stk.pop();
			}
		}
		return res;
	}
};