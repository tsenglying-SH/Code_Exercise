/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//logn + k 的写法，move_upper move_lower一定要注意 形参是引用， 无返回值却有返回类型时也会报错的
class Solution {

public:
	vector<int> closestKValues(TreeNode* root, double target, int k) {
		vector <int> result;
		if (root == NULL) { return result; }

		stack<TreeNode *> upper_stack = get_stack(root, target);
		stack<TreeNode *> lower_stack = get_stack(root, target);

		if (target > upper_stack.top()->val) {
			move_upper(upper_stack);
		}

		else {
			move_lower(lower_stack);
		}

		for (int i = 0; i < k; i++) {
			if (lower_is_closer(lower_stack, upper_stack, target)) {
				result.push_back(lower_stack.top()->val);
				move_lower(lower_stack);
			}
			else {
				result.push_back(upper_stack.top()->val);
				move_upper(upper_stack);
			}
		}
		return result;
	}
private:
	stack<TreeNode *> get_stack(TreeNode* root, double target) {
		stack<TreeNode *> S;
		if (root == NULL) { return S; }

		while (root != NULL) {
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

	stack<TreeNode *> move_upper(stack<TreeNode *> &upper_stack) {
		if (upper_stack.empty()) { return upper_stack; }

		TreeNode * cur_node = upper_stack.top();
		if (cur_node->right != NULL) {
			TreeNode * node = cur_node->right;
			while (node) {
				upper_stack.push(node);
				node = node->left;
			}
		}
		else {
			TreeNode * node = upper_stack.top(); upper_stack.pop();
			while (!upper_stack.empty() && upper_stack.top()->right == node) {
				node = upper_stack.top(); upper_stack.pop();
			}
		}
		return upper_stack;
	}

	stack<TreeNode *> move_lower(stack<TreeNode *> &lower_stack) {
		if (lower_stack.empty()) { return lower_stack; }

		TreeNode * cur_node = lower_stack.top();
		if (cur_node->left != NULL) {
			TreeNode * node = cur_node->left;
			while (node) {
				lower_stack.push(node);
				node = node->right;
			}
		}
		else {
			TreeNode * node = lower_stack.top(); lower_stack.pop();
			while (!lower_stack.empty() && lower_stack.top()->left == node) {
				node = lower_stack.top(); lower_stack.pop();
			}
		}
		return lower_stack;
	}

	bool lower_is_closer(stack<TreeNode *> lower_stack, stack<TreeNode *> upper_stack, double target) {
		if (lower_stack.empty()) {
			return false;
		}
		if (upper_stack.empty()) {
			return true;
		}
		return target - lower_stack.top()->val < upper_stack.top()->val - target;
	}
};