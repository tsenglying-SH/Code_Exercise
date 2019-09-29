// build Trie then DFS, time O(mn 3^L * L)
class TrieNode {
public:
	vector<TrieNode*> post;
	string saved_word;
	TrieNode() : saved_word(""), post(26, nullptr) {}
};

class Solution {
public:
	/**
	* @param board: A list of lists of character
	* @param words: A list of string
	* @return: A list of string
	*/
	vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
		// write your code here
		if (words.empty()) {
			return{};
		}
		if (board.empty() || board[0].empty()) {
			return{};
		}

		unordered_set<string> res_set;
		int m = board.size(), n = board[0].size();
		TrieNode *trieRoot = buildTrie(words);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (trieRoot->post[board[i][j] - 'a']) {
					TrieNode *node = trieRoot->post[board[i][j] - 'a'];
					char origin_char = board[i][j];
					board[i][j] = ' ';
					search(node, board, i, j, res_set);
					board[i][j] = origin_char;
				}
			}
		}

		return vector<string>(res_set.begin(), res_set.end());
	}

	void search(TrieNode *node, vector<vector<char>> &board, int i, int j, unordered_set<string> &res_set) {
		if (node->saved_word != "") {
			res_set.insert(node->saved_word);
		}

		vector<int> dx = { 1, 0, -1, 0 };
		vector<int> dy = { 0, 1, 0, -1 };
		int m = board.size(), n = board[0].size();

		for (int idx = 0; idx < 4; idx++) {
			int new_x = i + dx[idx], new_y = j + dy[idx];
			// check the boundary
			if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) {
				continue;
			}
			// check whether it's visited
			if (board[new_x][new_y] == ' ') {
				continue;
			}
			char c = board[new_x][new_y];
			if (node->post[c - 'a'] != nullptr) {
				board[new_x][new_y] = ' ';
				search(node->post[c - 'a'], board, new_x, new_y, res_set);
				board[new_x][new_y] = c;
			}
		}
	}

	TrieNode * buildTrie(const vector<string> &words) {
		TrieNode *root = new TrieNode();
		for (string word : words) {
			TrieNode *node = root;
			for (char c : word) {
				if (node->post[c - 'a'] == nullptr) {
					node->post[c - 'a'] = new TrieNode();
				}
				node = node->post[c - 'a'];
			}
			node->saved_word = word;
		}
		return root;
	}
};