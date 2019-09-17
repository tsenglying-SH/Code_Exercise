/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//logn + k method£¬move_upper move_lower pay attention to the return value and the parameter should use "&"
class Solution {
public:
	/**
	* @param root: the given BST
	* @param target: the given target
	* @param k: the given k
	* @return: k values in the BST that are closest to the target
	*/
	vector<int> closestKValues(TreeNode * root, double target, int k) {
		// write your code here
		if (!root || k <= 0) { return{}; }

		stack<TreeNode*> upper_stack = initial_stack(root, target);
		stack<TreeNode*> lower_stack = upper_stack;
		if (lower_stack.top()->val < target) {
			move_upper(upper_stack);
		}
		else {
			move_lower(lower_stack);
		}

		vector<int> res;
		for (int num = 0; num < k; num++) {
			if (lower_is_closer(lower_stack, upper_stack, target)) {
				res.push_back(lower_stack.top()->val);
				move_lower(lower_stack);
			}
			else {
				res.push_back(upper_stack.top()->val);
				move_upper(upper_stack);
			}
		}
		return res;
	}

	stack<TreeNode*> initial_stack(TreeNode * root, double target) {
		stack<TreeNode*> S;

		if (!root) {
			return S;
		}

		while (root) {
			S.push(root);
			if (target < root->val) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
		return S;
	}

	void move_upper(stack<TreeNode*> &S) {
		if (S.empty()) {
			return;
		}
		TreeNode* cur_node = S.top();
		if (cur_node->right) {
			TreeNode* node = cur_node->right;
			while (node) {
				S.push(node);
				node = node->left;
			}
		}
		else {
			TreeNode* node = S.top(); S.pop();
			while (!S.empty() && S.top()->right == node) {
				node = S.top(); S.pop();
			}
		}
	}

	void move_lower(stack<TreeNode*> &S) {
		if (S.empty()) {
			return;
		}
		TreeNode* cur_node = S.top();
		if (cur_node->left) {
			TreeNode* node = cur_node->left;
			while (node) {
				S.push(node);
				node = node->right;
			}
		}
		else {
			TreeNode* node = S.top(); S.pop();
			while (!S.empty() && S.top()->left == node) {
				node = S.top(); S.pop();
			}
		}
	}
	bool lower_is_closer(const stack<TreeNode*> &lower_stack, const stack<TreeNode*> &upper_stack, double target) {
		if (lower_stack.empty()) {
			return false;
		}
		if (upper_stack.empty()) {
			return true;
		}
		return target - lower_stack.top()->val < upper_stack.top()->val - target;
	}
};