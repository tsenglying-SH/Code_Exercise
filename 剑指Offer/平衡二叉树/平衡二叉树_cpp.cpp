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
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		return depth(root) != -1;
	}

	int depth(TreeNode *root) {
		if (!root) return 0;
		int h_left = depth(root->left);
		int h_right = depth(root->right);
		if (abs(h_left - h_right) > 1 || h_left == -1 || h_right == -1) {
			return -1;
		}
		return max(h_left, h_right) + 1;
	}
};