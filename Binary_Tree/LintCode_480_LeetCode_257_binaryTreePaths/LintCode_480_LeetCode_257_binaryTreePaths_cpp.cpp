/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// Recursive DFS to traverse all the path
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == nullptr) {
			return{};
		}

		vector<string> all_path;
		string path = to_string(root->val);
		dfs(root, path, all_path);
		return all_path;
	}

	void dfs(TreeNode* root, const string &path, vector<string> & all_path) {
		if (root == nullptr) {
			return;
		}
		// if root is the last node
		if (root->left == nullptr && root->right == nullptr) {
			all_path.push_back(path);
		}
		// continue dfs if necessary
		if (root->left) {
			dfs(root->left, path + "->" + to_string(root->left->val), all_path);
		}
		if (root->right) {
			dfs(root->right, path + "->" + to_string(root->right->val), all_path);
		}
	}
};