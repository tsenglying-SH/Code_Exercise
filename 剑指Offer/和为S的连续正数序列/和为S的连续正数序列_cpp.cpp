// deque method, time O(n), space O(n)
class Solution {
public:
	vector<vector<int> > findContinuousSequence(int sum) {
		if (sum <= 0) return{};
		deque<int> dq; dq.push_back(1);
		vector<vector<int>> res;
		int s = 1;
		while (dq.back() <= sum / 2 + 1) {
			if (s < sum) dq.push_back(dq.back() + 1), s += dq.back();
			else if (s > sum) s -= dq.front(), dq.pop_front();
			else res.push_back(vector<int>(dq.begin(), dq.end())), dq.push_back(dq.back() + 1), s += dq.back();
		}
		return res;
	}
};

// 2 pointers method, time O(n), space O(1)
class Solution {
public:
	vector<vector<int> > findContinuousSequence(int sum) {
		if (sum <= 0) return{};
		int i = 1, j = 1, s = 1;
		vector<vector<int>> res;
		while (j <= sum / 2 + 1) {
			if (s < sum) s += ++j;
			else if (s > sum) s -= i++;
			else {
				vector<int> path;
				for (int num = i; num <= j; ++num) path.push_back(num);
				res.push_back(path);
				s += ++j;
			};
		}
		return res;
	}
};