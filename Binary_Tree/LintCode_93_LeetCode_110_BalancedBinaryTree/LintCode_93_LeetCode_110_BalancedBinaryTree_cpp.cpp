/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// Recusive Method, piggy back on calculating the tree Height
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		// corner case
		if (root == nullptr) {
			return true;
		}
		return treeHeight(root) != -1;
	}

	int treeHeight(TreeNode * root) {
		if (root == nullptr) {
			return 0;
		}
		// recursive calculate left height
		int left = treeHeight(root->left);
		// recursive calculate right height
		int right = treeHeight(root->right);
		// if height not balance or imbalane yet, return -1
		if (left == -1 || right == -1 || abs(left - right) > 1) {
			return -1;
		}
		// if balance, height + 1
		return max(left, right) + 1;
	}
};