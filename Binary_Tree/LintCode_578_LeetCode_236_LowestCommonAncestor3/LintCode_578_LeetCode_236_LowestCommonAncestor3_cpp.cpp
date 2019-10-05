/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// Recursive method, postorder traverse
class Solution {
private:
	TreeNode* ans = nullptr;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return nullptr;
		}
		search_in_tree(root, p, q);
		return ans;
	}

	bool search_in_tree(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return false;
		}
		// all elements in the tree are different, so left, mid and right cannot be set to true due to 1 node.
		bool left = search_in_tree(root->left, p, q);
		bool right = search_in_tree(root->right, p, q);
		bool mid = root == p || root == q;

		if (left + right + mid >= 2) {
			ans = root;
		}
		return left || right || mid;
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
//iteration version
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return nullptr;
		}
		unordered_map<TreeNode*, TreeNode*> parent;
		parent[root] = nullptr;
		stack<TreeNode*> S; S.push(root);

		while (!S.empty()) {
			TreeNode* node = S.top(); S.pop();
			if (node->left) {
				parent[node->left] = node;
				S.push(node->left);
			}
			if (node->right) {
				parent[node->right] = node;
				S.push(node->right);
			}
		}
		if (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
			return nullptr;
		}

		unordered_set<TreeNode*> ancestors;
		while (p) {
			ancestors.insert(p);
			p = parent[p];
		}

		while (q) {
			if (ancestors.find(q) != ancestors.end()) {
				return q;
			}
			q = parent[q];
		}
		return nullptr;
	}
};