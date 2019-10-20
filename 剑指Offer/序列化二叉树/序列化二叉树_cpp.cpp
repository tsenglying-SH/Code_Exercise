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

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root) return "";
		string res = "";
		queue<TreeNode *> Q; Q.push(root);
		while (!Q.empty()) {
			TreeNode *node = Q.front(); Q.pop();
			if (node) {
				res += to_string(node->val) + " ";
				Q.push(node->left);
				Q.push(node->right);
			}
			else {
				res += "# ";
			}
		}
		int j = res.size() - 1;
		while (j > 0 && res[j] == ' ') j--;
		res = res.substr(0, j + 1);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) return nullptr;
		int i = 0;
		while (i < data.size() && data[i] != ' ') ++i;
		string tmp = data.substr(0, i); ++i;
		int begin = 0;
		TreeNode *head = new TreeNode(stoi(tmp));
		queue<TreeNode *> Q; Q.push(head);

		while (!Q.empty()) {
			TreeNode *node = Q.front(); Q.pop();

			begin = i;
			while (i < data.size() && data[i] != ' ') ++i;
			tmp = data.substr(begin, i - begin); ++i;
			if (tmp != "#") {
				node->left = new TreeNode(stoi(tmp));
				Q.push(node->left);
			}

			begin = i;
			while (i < data.size() && data[i] != ' ') ++i;
			tmp = data.substr(begin, i - begin); ++i;
			if (tmp != "#") {
				node->right = new TreeNode(stoi(tmp));
				Q.push(node->right);
			}
		}
		return head;
	}
};