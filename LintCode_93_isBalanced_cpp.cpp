/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/
//参考自九章算法C++题解
class Solution {
public:
	/**
	* @param root: The root of binary tree.
	* @return: True if this Binary tree is Balanced, or false.
	*/
	int depth(TreeNode * root) {
		if (!root) { return 0; }

		int left_depth = depth(root->left);
		int right_depth = depth(root->right);

		if (left_depth == -1 || right_depth == -1 || abs(left_depth - right_depth) > 1) {
			return -1;
		}

		return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
	}

	bool isBalanced(TreeNode * root) {
		// write your code here
		return depth(root) != -1;
	}
};