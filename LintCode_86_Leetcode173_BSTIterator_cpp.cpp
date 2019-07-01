/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//简便写法 参考leetcode 题解
class BSTIterator {
private:
	stack <TreeNode *> S;

public:
	BSTIterator(TreeNode* root) {
		while (root) {
			S.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode * next_node = S.top(); S.pop();
		TreeNode * node = next_node->right;
		while (node) {
			S.push(node);
			node = node->left;
		}
		return next_node->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return S.size() > 0;
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
* Example of iterate a tree:
* BSTIterator iterator = BSTIterator(root);
* while (iterator.hasNext()) {
*    TreeNode * node = iterator.next();
*    do something for node
*/
//参考lincode python题解 C++版本

class BSTIterator {
private:
	stack<TreeNode *> S;

public:
	/*
	* @param root: The root of binary tree.
	*/BSTIterator(TreeNode * root) {
	// do intialization if necessary
	while (root) {
		S.push(root);
		root = root->left;
	}
}

	  /*
	  * @return: True if there has next node, or false
	  */
	  bool hasNext() {
		  // write your code here
		  return !S.empty();
	  }

	  /*
	  * @return: return next node
	  */
	  TreeNode * next() {
		  // write your code here
		  if (!hasNext()) { return NULL; }

		  TreeNode * cur_node = S.top();
		  if (cur_node->right) {
			  TreeNode * node = cur_node->right;
			  while (node) {
				  S.push(node);
				  node = node->left;
			  }
		  }
		  else {
			  TreeNode * node = S.top(); S.pop();
			  while (!S.empty() && S.top()->right == node) {
				  node = S.top(); S.pop();
			  }
		  }
		  return cur_node;
	  }
};
