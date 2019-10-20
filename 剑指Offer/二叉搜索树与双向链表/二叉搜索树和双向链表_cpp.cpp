/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// origin naive method myself, time O(nlogn), move may be not necessary, we only need to know the head and tail of the interval
class Solution {
public:
	TreeNode* convert(TreeNode* root) {
		if (!root) return nullptr;
		TreeNode *node = dfs(root);
		while (node->left) {
			node = node->left;
		}
		return node;
	}

	TreeNode *dfs(TreeNode *node) {
		if (!node) return nullptr;
		if (!node->left && !node->right) return node;
		TreeNode *left = dfs(node->left);
		if (left) {
			while (left->right) {
				left = left->right;
			}
			left->right = node;
		}
		TreeNode *right = dfs(node->right);
		if (right) {
			while (right->left) {
				right = right->left;
			}
			right->left = node;
		}
		node->left = left;
		node->right = right;
		return node;
	}
};

// Acwing solution, time O(n)

class Solution {
public:
	TreeNode* convert(TreeNode* root) {
		if (!root) return nullptr;
		auto bound = dfs(root);
		return bound.first;
	}

	pair<TreeNode *, TreeNode *> dfs(TreeNode *node) {
		if (!node->left && !node->right) return{ node, node };
		if (node->left && node->right) {
			auto l_bound = dfs(node->left), r_bound = dfs(node->right);
			l_bound.second->right = node;
			node->left = l_bound.second;
			r_bound.first->left = node;
			node->right = r_bound.first;
			return{ l_bound.first, r_bound.second };
		}
		if (node->left) {
			auto l_bound = dfs(node->left);
			l_bound.second->right = node;
			node->left = l_bound.second;
			return{ l_bound.first, node };
		}

		if (node->right) {
			auto r_bound = dfs(node->right);
			r_bound.first->left = node;
			node->right = r_bound.first;
			return{ node, r_bound.second };
		}
	}
};