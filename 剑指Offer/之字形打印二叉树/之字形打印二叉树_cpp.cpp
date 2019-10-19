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
		bool reverse = false;
		while (!Q.empty()) {
			int size = Q.size();
			vector<int> level;
			for (int i = 0; i < size; ++i) {
				TreeNode *node = Q.front(); Q.pop();
				level.push_back(node->val);
				if (node->left) Q.push(node->left);
				if (node->right) Q.push(node->right);
			}
			if (reverse) {
				res.push_back(vector<int>(level.rbegin(), level.rend()));
				reverse = false;
			}
			else {
				res.push_back(level);
				reverse = true;
			}
		}
		return res;
	}
};