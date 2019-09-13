/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
// BFS method
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == nullptr) { return ""; }
		vector<string> res_raw;
		queue<TreeNode*> Q; Q.push(root);

		while (!Q.empty()) {
			TreeNode* node = Q.front(); Q.pop();
			if (node != nullptr) {
				Q.push(node->left);
				Q.push(node->right);
				res_raw.push_back(to_string(node->val));
			}
			else {
				res_raw.push_back("#");
			}
		}
		// eliminate the "#" in tail
		while (res_raw.back() == "#") {
			res_raw.pop_back();
		}
		string res_str = "";
		for (auto str : res_raw) {
			res_str += str + " ";
		}
		return res_str;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.size() == 0) { return nullptr; }

		int i = 0; string tmp = "";
		while (i < data.size() && data[i] != ' ') {
			tmp += data[i];
			i++;
		}
		i++;
		// cout << "tmp0:" << tmp << endl;
		// here tmp cannot be "#" or ""
		TreeNode* root = new TreeNode(stoi(tmp));
		queue<TreeNode*> Q; Q.push(root);

		// ensure i point something and Q is not empty
		while (i < data.size() && !Q.empty()) {
			TreeNode* node = Q.front(); Q.pop();

			tmp = "";
			while (i < data.size() && data[i] != ' ') {
				tmp += data[i];
				i++;
			}
			i++;
			// cout << "tmp1:" << tmp << endl;
			// ensure tmp is not empty or "#"
			if (tmp != "#" && tmp.size() != 0) {
				node->left = new TreeNode(stoi(tmp));
				Q.push(node->left);
			}

			tmp = "";
			while (i < data.size() && data[i] != ' ') {
				tmp += data[i];
				i++;
			}
			i++;
			// cout << "tmp2:" << tmp << endl;
			// ensure tmp is not empty or "#"
			if (tmp != "#" && tmp.size() != 0) {
				node->right = new TreeNode(stoi(tmp));
				Q.push(node->right);
			}
		}
		return root;
	}
};