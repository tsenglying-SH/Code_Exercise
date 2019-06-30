/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//参考leetcode题解 Recursive版本
class Solution {
private:
	TreeNode * ans = nullptr;

public:
	/*
	* @param root: The root of the binary tree.
	* @param A: A TreeNode
	* @param B: A TreeNode
	* @return: Return the LCA of the two nodes.
	*/
	bool recurse_tree(TreeNode * current_node, TreeNode * p, TreeNode * q) {
		if (current_node == NULL) {
			return false;
		}

		bool left = recurse_tree(current_node->left, p, q);
		bool right = recurse_tree(current_node->right, p, q);

		bool mid = (current_node == p) || (current_node == q);

		if (int(left) + int(right) + int(mid) >= 2) {
			ans = current_node;
		}

		return mid || left || right;
	}

	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
		// write your code here
		recurse_tree(root, A, B);
		return ans;
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
//iteration版本
class Solution {
public:
	/*
	* @param root: The root of the binary tree.
	* @param A: A TreeNode
	* @param B: A TreeNode
	* @return: Return the LCA of the two nodes.
	*/
	TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
		// write your code here
		if (root == NULL) { return NULL; }

		unordered_map <TreeNode *, TreeNode *> parents = { { root, NULL } };
		stack <TreeNode *> S;
		S.push(root);
		while (!parents.count(A) || !parents.count(B)) {
			if (S.size() == 0) { break; }

			TreeNode * cur_node = S.top(); S.pop();

			if (cur_node->left) {
				parents[cur_node->left] = cur_node;
				S.push(cur_node->left);
			}
			if (cur_node->right) {
				parents[cur_node->right] = cur_node;
				S.push(cur_node->right);
			}
		}
		unordered_set<TreeNode *> ancestors;

		while (A) {
			ancestors.insert(A);
			if (parents.count(A)) {
				A = parents[A];
			}
			else {
				break;
			}
		}

		while (!ancestors.count(B)) {
			if (parents.count(B)) {
				B = parents[B];
			}
			else {
				return NULL;
			}
		}
		return B;
	}
};