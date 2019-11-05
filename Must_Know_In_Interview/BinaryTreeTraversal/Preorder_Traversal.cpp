/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// Recursion Method, time O(n), space O(n)
class Solution {
private:
	vector<int> res;
public:
	vector<int> preorderTraversal(TreeNode* root) {
		preorder(root);
		return res;
	}

	void preorder(TreeNode *root) {
		if (!root) return;
		res.push_back(root->val);

		preorder(root->left);
		preorder(root->right);
	}
};


// iterative method 1, just translate recursion method, time O(n), space O(n)
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (!root) return{};
		vector<int> res;
		stack<TreeNode *> stk; stk.push(root);
		while (!stk.empty()) {
			TreeNode *node = stk.top(); stk.pop();
			res.push_back(node->val);
			if (node->right) stk.push(node->right);
			if (node->left) stk.push(node->left);
		}
		return res;
	}
};


// iterative method 2, implement according to traversal rules, time O(n), space O(n), this method may be the best
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (!root) return{};
		stack<TreeNode *> stk;
		vector<int> res;
		TreeNode *node = root;
		while (true) {
			while (node) {
				// record the current node
				res.push_back(node->val);
				// push its right son into stack for the traversal in the future
				if (node->right) stk.push(node->right);
				// traverse along left son
				node = node->left;
			}
			// no node more, break
			if (stk.empty()) break;
			// if no left sons more, traverse right son saved before
			node = stk.top(); stk.pop();

		}
		return res;
	}
};