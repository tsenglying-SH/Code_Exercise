/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		// write your code here
		return height(root) != -1;
	}

	int height(TreeNode *root) {
		if (!root) return 0;
		int l_h = height(root->left);
		int r_h = height(root->right);

		if (l_h == -1 || r_h == -1 || abs(l_h - r_h) > 1) {
			return -1;
		}

		return max(l_h, r_h) + 1;
	}
};