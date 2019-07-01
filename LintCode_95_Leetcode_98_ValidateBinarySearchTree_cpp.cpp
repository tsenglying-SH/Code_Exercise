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
//参考九章算法题解 iteration版本
class Solution {
public:
	/**
	* @param root: The root of binary tree.
	* @return: True if the binary tree is BST, or false
	*/
	bool isValidBST(TreeNode * root) {
		// write your code here
		if (!root) { return true; }

		stack<TreeNode *> S;
		while (root) {
			S.push(root);
			root = root->left;
		}

		TreeNode * last_node = S.top();

		while (S.size() != 0) {
			TreeNode * cur_node = S.top(); S.pop();
			if (cur_node->right) {
				cur_node = cur_node->right;
				while (cur_node) {
					S.push(cur_node);
					cur_node = cur_node->left;
				}
			}

			if (S.size() != 0) {
				if (last_node->val >= S.top()->val) {
					return false;
				}
				last_node = S.top();
			}
		}
		return true;
	}
};


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//参考九章算法题解 recursive版本
class Solution {
private:
	bool ans = true;
	TreeNode * lastNode = NULL;
public:
	/**
	* @param root: The root of binary tree.
	* @return: True if the binary tree is BST, or false
	*/
	bool isValidBST(TreeNode * root) {
		// write your code here
		validate(root);
		return ans;
	}
	void validate(TreeNode * root) {
		if (!root) { return; }

		validate(root->left);
		if (lastNode != NULL && lastNode->val >= root->val) {
			ans = false;
		}
		lastNode = root;
		validate(root->right);
	}
};