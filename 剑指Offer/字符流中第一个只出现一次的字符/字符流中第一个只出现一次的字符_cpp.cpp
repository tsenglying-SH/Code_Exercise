// time totally O(n), on average O(1), space O(n), if char only a-z, it's O(1), exacylt O(26)
class Solution {
private:
	unordered_map<char, int> char_cnt;
	queue<char> Q;

public:
	//Insert one char from stringstream
	void insert(char ch) {
		if (++char_cnt[ch] == 1) {
			Q.push(ch);
		}
		else {
			while (!Q.empty() && char_cnt[Q.front()] > 1) Q.pop();
		}
	}
	//return the first appearence once char in current stringstream
	char firstAppearingOnce() {
		return Q.empty() ? '#' : Q.front();
	}
};