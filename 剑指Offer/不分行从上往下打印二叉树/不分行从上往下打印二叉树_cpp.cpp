/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> printFromTopToBottom(TreeNode* root) {
		if (!root) return{};
		queue<TreeNode *> Q; Q.push(root);
		vector<int> res;

		while (!Q.empty()) {
			TreeNode *node = Q.front(); Q.pop();
			res.push_back(node->val);

			if (node->left) Q.push(node->left);
			if (node->right) Q.push(node->right);
		}
		return res;
	}
};