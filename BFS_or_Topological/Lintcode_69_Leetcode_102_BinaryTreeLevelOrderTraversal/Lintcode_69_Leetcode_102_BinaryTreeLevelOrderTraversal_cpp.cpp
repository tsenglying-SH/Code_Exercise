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

// Basic BFS
class Solution {
public:
	/**
	* @param root: A Tree
	* @return: Level order a list of lists of integer
	*/
	vector<vector<int>> levelOrder(TreeNode * root) {
		// write your code here
		if (root == nullptr) {
			return{};
		}

		vector<vector<int>> res;
		queue<TreeNode *> Q; Q.push(root);
		vector<int> level;

		while (!Q.empty()) {
			// here you should save the size, if use Q.size() directly in for loop, Q.push() Q.pop() will change the size
			int size = Q.size(); 
			level.erase(level.begin(), level.end());

			for (int i = 0; i < size; i++) {
				TreeNode *node = Q.front(); Q.pop();
				level.push_back(node->val);

				if (node->left != nullptr) {
					Q.push(node->left);
				}

				if (node->right != nullptr) {
					Q.push(node->right);
				}
			}
			res.push_back(level);
		}
		return res;
	}
};