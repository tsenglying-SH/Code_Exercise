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
	vector<vector<int>> findPath(TreeNode* root, int sum) {
		if (!root) return{};
		vector<int> path;
		vector<vector<int>> res;
		dfs(root, path, res, sum);
		return res;
	}

	void dfs(TreeNode *node, vector<int> &path, vector<vector<int>> &res, int sum) {
		if (!node) return;
		path.push_back(node->val);
		sum -= node->val;

		if (!node->left && !node->right && sum == 0) {
			res.push_back(path);
			// back tracking if return
			path.pop_back();
			return;
		}
		if (sum <= 0) {
			// back tracking if return
			path.pop_back();
			return;
		}

		dfs(node->left, path, res, sum);
		dfs(node->right, path, res, sum);
		// back tracking if return
		path.pop_back();
	}
};