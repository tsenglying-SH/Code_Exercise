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

//�ݹ鷽�� �ο������㷨python����
class Solution {
public:
	/**
	* @param root: a TreeNode, the root of the binary tree
	* @return: nothing
	*/
	void flatten(TreeNode * root) {
		// write your code here
		if (root == NULL) {
			return;
		}

		if (last_node != NULL) {
			last_node->left = NULL;
			last_node->right = root;
		}

		last_node = root;
		TreeNode * left = root->left;
		TreeNode * right = root->right;
		flatten(left);
		flatten(right);
	}
private:
	TreeNode * last_node = nullptr;
};



//�ǵݹ鷽�� �ο������㷨���
class Solution {
public:
	/**
	* @param root: a TreeNode, the root of the binary tree
	* @return: nothing
	*/
	void flatten(TreeNode * root) {
		// write your code here
		if (root == NULL) { return; }
		while (root) {
			if (root->left) {
				TreeNode * pre = root->left;
				while (pre->right) {
					pre = pre->right;
				}
				pre->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
	}
};