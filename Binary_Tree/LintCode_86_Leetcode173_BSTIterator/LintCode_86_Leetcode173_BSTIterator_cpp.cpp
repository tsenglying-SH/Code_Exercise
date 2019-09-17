/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// iterative inorder traverse template
class BSTIterator {
private:
	TreeNode* node;
	stack<TreeNode*> S;

public:
	BSTIterator(TreeNode* root) {
		node = root;
		while (node) {
			S.push(node);
			node = node->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		if (S.empty()) {
			return -1;
		}

		node = S.top(); S.pop();
		int ans = node->val;

		node = node->right;
		while (node) {
			S.push(node);
			node = node->left;
		}

		return ans;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return S.size() > 0;
	}
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/

