/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// Recursive method, time O(n), space O(n)
class Solution {
private:
	vector<int> res;
public:
	/**
	* @param root: A Tree
	* @return: Inorder in ArrayList which contains node values.
	*/
	vector<int> inorderTraversal(TreeNode * root) {
		// write your code here
		inorder(root);
		return res;
	}
	void inorder(TreeNode *root) {
		if (!root) return;
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
	}
};


// iterative method according to traversal rules, time O(n), space O(n)
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return{};
		stack<TreeNode *> stk;
		vector<int> res;
		TreeNode *node = root;
		while (true) {
			while (node) {
				stk.push(node);
				node = node->left;
			}

			if (stk.empty()) break;
			node = stk.top(); stk.pop();
			res.push_back(node->val);

			node = node->right;
		}
		return res;
	}
};