/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// time O(n)
class Solution {
public:
	void mirror(TreeNode* root) {
		// nullptr nothing to mirror
		if (!root) { return; }
		// swap left son and right son
		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		//recursively mirror two sons
		mirror(root->left);
		mirror(root->right);
	}
};