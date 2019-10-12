// Recursive way from Acwing, time O(n^2), space O(h)
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
			return nullptr;
		}

		return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder, int p_start, int p_end, int i_start, int i_end) {
		if (p_start > p_end || i_start > i_end) {
			return nullptr;
		}
		TreeNode *node = new TreeNode(preorder[p_start]);
		if (p_start == p_end && i_start == i_end) {
			return node;
		}
		// here, some optimization can be done via save the position in a map to avoid too much linear search
		int i_center = i_start;
		for (int i = i_start; i <= i_end; ++i) {
			if (inorder[i] == preorder[p_start]) {
				i_center = i;
			}
		}
		// the difficult part here, to calculate p_start, p_end, i_start, i_end
		node->left = helper(preorder, inorder, p_start + 1, p_start + i_center - i_start, i_start, i_center - 1);
		node->right = helper(preorder, inorder, p_start + i_center - i_start + 1, p_end, i_center + 1, i_end);
		return node;
	}
};

// optimization version, time O(n), space O(h + n)
class Solution {
private:
	unordered_map<int, int> e_p;

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
			return nullptr;
		}
		for (int i = 0; i < inorder.size(); ++i) {
			e_p[inorder[i]] = i;
		}

		return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder, int p_start, int p_end, int i_start, int i_end) {
		if (p_start > p_end || i_start > i_end) {
			return nullptr;
		}
		TreeNode *node = new TreeNode(preorder[p_start]);
		if (p_start == p_end && i_start == i_end) {
			return node;
		}
		int i_center = e_p[preorder[p_start]];

		node->left = helper(preorder, inorder, p_start + 1, p_start + i_center - i_start, i_start, i_center - 1);
		node->right = helper(preorder, inorder, p_start + i_center - i_start + 1, p_end, i_center + 1, i_end);
		return node;
	}
};