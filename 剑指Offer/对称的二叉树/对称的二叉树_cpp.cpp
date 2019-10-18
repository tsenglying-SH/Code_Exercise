/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// Recursive method
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		// empty is symmetric
		if (!root) return true;
		// check left son and right son's value is the same.
		return dfs(root->left, root->right);
	}

	bool dfs(TreeNode *node1, TreeNode *node2) {
		if (!node1 || !node2) return !node1 && !node2;
		// recursive check the sons of son
		return node1->val == node2->val
			&& dfs(node1->left, node2->right)
			&& dfs(node1->right, node2->left);
	}
};

// iterative method
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		TreeNode *p_left = root, *p_right = root;
		stack<TreeNode *> s1, s2;
		while (p_left) { s1.push(p_left); p_left = p_left->left; }
		while (p_right) { s2.push(p_right); p_right = p_right->right; }
		if (s1.size() != s2.size()) return false;
		p_left = s1.top(); p_right = s2.top();

		while (p_left != root && p_right != root) {
			p_left = p_left->right;
			p_right = p_right->left;

			while (p_left) { s1.push(p_left); p_left = p_left->left; }
			while (p_right) { s2.push(p_right); p_right = p_right->right; }

			if (!s1.empty()) p_left = s1.top(); s1.pop();
			if (!s2.empty()) p_right = s2.top(); s2.pop();
			if (p_left->val != p_right->val) return false;
		}
		return true;
	}
};