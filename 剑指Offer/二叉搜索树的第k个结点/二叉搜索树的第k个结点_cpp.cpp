// iteration method, inorder traverse, time O(k)
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
	TreeNode* kthNode(TreeNode* root, int k) {
		if (!root) return nullptr;
		TreeNode *p = root, *res = nullptr;
		stack<TreeNode *> S;
		while (k--) {
			while (p) {
				S.push(p);
				p = p->left;
			}
			if (S.empty()) return nullptr;
			p = S.top(); S.pop();
			res = p;
			p = p->right;
		}
		return res;
	}
};

// Recursive Method, time O(k)
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
private:
	TreeNode *res = nullptr;
public:
	TreeNode* kthNode(TreeNode* root, int k) {
		dfs(root, k);
		return res;
	}
	void dfs(TreeNode *root, int &k) {
		if (!root) return;
		dfs(root->left, k);
		k--;
		if (k == 0) res = root;
		// here stop unnecessary search
		if (k > 0) dfs(root->right, k);
	}
};