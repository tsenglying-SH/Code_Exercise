// A solution for Leetcode, O(26 nL^2 ), n is wordList length, L is word length
// Another way is biodirectional BFS, to be updated later.
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() || beginWord.size() != endWord.size() || beginWord.size() == 0) {
			return 0;
		}
		// use set instead of vector
		unordered_set<string> word_pool(wordList.begin(), wordList.end());
		queue<string> Q; Q.push(beginWord);
		int count = 1;

		while (!Q.empty()) {
			int size = Q.size();

			for (int i = 0; i < size; i++) {
				string word = Q.front(); Q.pop();
				if (word == endWord) {
					return count;
				}
				for (int j = 0; j < word.size(); j++) {
					for (char c = 'a'; c <= 'z'; c++) {
						string new_word = word;
						if (word[j] == c) {
							continue;
						}
						new_word[j] = c;
						if (word_pool.find(new_word) != word_pool.end()) {
							Q.push(new_word);
							word_pool.erase(new_word);
						}
					}
				}
			}
			count++;
		}
		return 0;
	}
};