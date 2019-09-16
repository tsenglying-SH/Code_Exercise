/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// naive inorder traverse method, time O(n), space O(n)
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		if (root == nullptr) {
			return -1;
		}
		vector<int> ans;
		inorder(root, ans);
		return ans[k - 1];
	}

	void inorder(TreeNode* root, vector<int> &ans) {
		if (root == nullptr) {
			return;
		}
		inorder(root->left, ans);
		ans.push_back(root->val);
		inorder(root->right, ans);
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

// Iterative method, using stack, time O(H + k), space O(H + k)
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		if (root == nullptr) {
			return -1;
		}

		stack<TreeNode*> S;

		while (true) {
			while (root != nullptr) {
				S.push(root);
				root = root->left;
			}

			root = S.top(); S.pop();
			if (!(--k)) {
				return root->val;
			}

			root = root->right;
		}
	}
};