// it's easy, if we have father information of nodes
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode *father;
*     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* p) {
		if (!p) return nullptr;
		TreeNode *node = p;
		if (p->right) {
			node = p->right;
			while (node->left) node = node->left;
			return node;
		}
		else {
			while (node->father && node == node->father->right) node = node->father;
			return node->father;
		}
	}
};