// Calculate the sum of tree and upgrate the minimum subtree along the way

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

class Solution {
private:
	int minimum = INT_MAX;
	TreeNode * minimum_root = nullptr;
public:
	/**
	* @param root: the root of binary tree
	* @return: the root of the minimum subtree
	*/
	TreeNode * findSubtree(TreeNode * root) {
		// write your code here
		if (root == nullptr) { return root; }
		sum_tree(root);
		return minimum_root;
	}

	int sum_tree(TreeNode * root) {
		if (root == nullptr) { return 0; }
		int sum_of_tree = sum_tree(root->left) + root->val + sum_tree(root->right);
		if (sum_of_tree < minimum) {
			minimum = sum_of_tree;
			minimum_root = root;
		}
		return sum_of_tree;
	}
};