/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// level order traversal
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return{};
		queue<TreeNode *> Q; Q.push(root);
		vector<vector<int>> res;

		while (!Q.empty()) {
			int size = Q.size();
			vector<int> level;
			for (int i = 0; i < size; ++i) {
				TreeNode *node = Q.front(); Q.pop();
				level.push_back(node->val);
				if (node->left) Q.push(node->left);
				if (node->right) Q.push(node->right);
			}
			res.push_back(level);
		}
		return res;
	}
};

// zigzag order traversal
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root) return{};
		queue<TreeNode *> Q; Q.push(root);
		vector<vector<int>> res;
		bool r_flag = false;
		while (!Q.empty()) {
			int size = Q.size();
			vector<int> level;

			for (int i = 0; i < size; ++i) {
				TreeNode *node = Q.front(); Q.pop();
				level.push_back(node->val);
				if (node->left) Q.push(node->left);
				if (node->right) Q.push(node->right);
			}
			if (r_flag) reverse(level.begin(), level.end());
			res.push_back(level);
			r_flag = !r_flag;
		}
		return res;
	}
};

// right-side view
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		if (!root) return{};
		queue<TreeNode *> Q; Q.push(root);
		vector<int> res;

		while (!Q.empty()) {
			int size = Q.size();

			for (int i = 0; i < size; ++i) {
				TreeNode *node = Q.front(); Q.pop();
				if (node->left) Q.push(node->left);
				if (node->right) Q.push(node->right);
				if (i == size - 1) res.push_back(node->val);
			}
		}
		return res;
	}
};