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

// search the target and update the answer along the way, time O(h)
class Solution {
public:
	/**
	* @param root: the given BST
	* @param target: the given target
	* @return: the value in the BST that is closest to the target
	*/
	int closestValue(TreeNode * root, double target) {
		// write your code here
		int ans_num = root->val;

		while (root != nullptr) {
			if (abs(root->val - target) < abs(ans_num - target)) {
				ans_num = root->val;
			}
			if (root->val == target) {
				return root->val;
			}
			if (root->val < target) {
				root = root->right;
			}
			else {
				root = root->left;
			}
		}
		return ans_num;
	}
};