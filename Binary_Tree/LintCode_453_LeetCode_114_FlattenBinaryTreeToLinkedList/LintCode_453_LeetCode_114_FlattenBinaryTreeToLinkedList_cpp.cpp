//Iteration Method
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
	void flatten(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		while (root != nullptr) {
			if (root->left != nullptr) {
				TreeNode* tail = root->left;
				while (tail->right) {
					tail = tail->right;
				}
				tail->right = root->right;
				root->right = root->left;
				root->left = nullptr;
			}
			root = root->right;
		}
	}
};




/**
* Definition of TreeNode:
* class TreeNode {
* public:
*     int val;
*     TreeNode *left, *right;
*     TreeNode(int val) {
*         this->val = val;
*         this->left = this->right = NULL;
*     }
* }
*/

//Recursive Method, refer to JiuZhang Python Code, a tricky way, I won't use it in interview I think.
class Solution {
public:
	/**
	* @param root: a TreeNode, the root of the binary tree
	* @return: nothing
	*/
	void flatten(TreeNode * root) {
		// write your code here
		if (root == NULL) {
			return;
		}

		if (last_node != NULL) {
			last_node->left = NULL;
			last_node->right = root;
		}

		last_node = root;
		TreeNode * left = root->left;
		TreeNode * right = root->right;
		flatten(left);
		flatten(right);
	}
private:
	TreeNode * last_node = nullptr;
};



