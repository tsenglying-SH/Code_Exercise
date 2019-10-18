/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// time O(mn)
class Solution {
public:
	bool hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		// empty node always false
		if (!pRoot1 || !pRoot2) { return false; }
		// if the node match the pRoot2 structure
		if (match(pRoot1, pRoot2)) { return true; }
		// match failed and match the sons of the pRoot1
		return hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2);
	}
	bool match(TreeNode *node1, TreeNode *node2) {
		// if node2 has no more sons, match succeed.
		if (!node2) { return true; }
		// if node1 is null but the node not, fail.
		// if the value of the roots are difference, fail.
		if (!node1 || node1->val != node2->val) { return false; }

		// roots matched and continue matching their sons.
		return match(node1->left, node2->left) && match(node1->right, node2->right);
	}
};