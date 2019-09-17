/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// Recursive Method 1, inorder traverse and record the lastNode to check validation
class Solution {
private:
	TreeNode* lastNode = nullptr;
	bool valid_flag = true;
public:
	bool isValidBST(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		validation(root);
		return valid_flag;
	}

	void validation(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		validation(root->left);
		if (lastNode && lastNode->val >= root->val) {
			valid_flag = false;
			return;
		}
		lastNode = root;
		validation(root->right);
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
// Recursive Method 2, recursively check every node with bound
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return validation(root);
	}

	bool validation(TreeNode * root, long long low = LLONG_MIN, long long up = LLONG_MAX) {
		if (!root) {
			return true;
		}

		if (root->val <= low || root->val >= up) {
			return false;
		}

		if (!validation(root->left, low, root->val)) {
			return false;
		}

		if (!validation(root->right, root->val, up)) {
			return false;
		}
		return true;
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
// Iterative Method, if last value >= root.val, false, if stack is empty, that's ok to return True
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (!root) {
			return true;
		}

		stack<TreeNode*> S;
		TreeNode* lastNode = nullptr;

		while (true) {
			while (root) {
				S.push(root);
				root = root->left;
			}

			if (S.empty()) {
				break;
			}

			root = S.top(); S.pop();

			if (lastNode && lastNode->val >= root->val) {
				return false;
			}
			lastNode = root;

			root = root->right;
		}
		return true;
	}
};


