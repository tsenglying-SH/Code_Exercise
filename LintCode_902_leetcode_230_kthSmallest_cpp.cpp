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

//²Î¿¼¾ÅÕÂËã·¨Áîºü³å python´úÂë
class Solution {
public:
	/**
	* @param root: the given BST
	* @param k: the given k
	* @return: the kth smallest element in BST
	*/
	int kthSmallest(TreeNode * root, int k) {
		// write your code here
		if (!root || k <= 0) { return 0; }

		TreeNode dummy(0);
		dummy.right = root;
		stack<TreeNode *> S;
		S.push(&dummy);

		for (int i = 0; i < k; i++) {
			TreeNode * node = S.top();
			S.pop();
			if (node->right != NULL) {
				node = node->right;
				while (node) {
					S.push(node);
					node = node->left;
				}
			}
			if (S.size() == 0) {
				break;
			}
		}
		return S.top()->val;
	}
};