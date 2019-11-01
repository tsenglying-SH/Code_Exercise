/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// LCA Solution refer to Leetcode time O(n)
class Solution {
private:
	TreeNode *res = nullptr;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		check(root, p, q);
		return res;
	}

	bool check(TreeNode* node, TreeNode *p, TreeNode *q) {
		// corner cases
		if (!p || !q || !node) return false;
		if (p == q) res = p;
		// no more need to continue
		if (res) return false;
		bool left = check(node->left, p, q);
		bool right = check(node->right, p, q);
		bool mid = node == p || node == q;
		if (mid + left + right >= 2) {
			res = node;
			return false;
		}
		return mid || left || right;
	}
};

// a similar but concise solution, time O(n)
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q) return nullptr;
		if (root == p || root == q) return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left && right) return root;
		if (left) return left;
		return right;
	}
};