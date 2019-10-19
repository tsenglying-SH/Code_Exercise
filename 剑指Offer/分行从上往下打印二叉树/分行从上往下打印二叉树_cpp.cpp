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
	vector<vector<int>> printFromTopToBottom(TreeNode* root) {
		if (!root) return{};
		queue<TreeNode *> Q; Q.push(root);
		vector<vector<int>> res;

		while (!Q.empty()) {
			int size = Q.size();
			vector<int> layer;
			for (int i = 0; i < size; ++i) {
				TreeNode *node = Q.front(); Q.pop();
				layer.push_back(node->val);
				if (node->left) Q.push(node->left);
				if (node->right) Q.push(node->right);
			}
			res.push_back(layer);
		}
		return res;
	}
};