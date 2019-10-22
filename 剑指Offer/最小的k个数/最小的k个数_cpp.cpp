// partition method, time O(n + klogk), space O(1)
class Solution {
public:
	vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty() || k <= 0 || k > input.size()) return{};
		vector<int> res;
		partition(input, 0, input.size() - 1, k, res);
		sort(res.begin(), res.end());
		return res;
	}

	void partition(vector<int> &nums, int start, int end, int k, vector<int> &res) {
		if (start > end) return;
		if (start == end && k == 1) {
			res.push_back(nums[start]);
			return;
		}
		int l = start, r = end;
		int mid = l + (r - l) / 2;
		int pivot = nums[mid];

		while (l <= r) {
			while (l <= r && nums[l] < pivot) l++;
			while (l <= r && nums[r] > pivot) r--;
			if (l <= r) {
				swap(nums[l++], nums[r--]);
			}
		}

		if (start + k - 1 <= r) {
			partition(nums, start, r, k, res);
		}
		else if (start + k - 1 >= l) {
			res.insert(res.end(), nums.begin() + start, nums.begin() + l);
			partition(nums, l, end, k - l + start, res);
		}
		else {
			res.insert(res.end(), nums.begin() + start, nums.begin() + l);
		}

	}
};


// heap based method, time O(nkogk)
class Solution {
public:
	vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty() || k > input.size() || k <= 0) return{};
		priority_queue<int, vector<int>> pq;
		for (int i = 0; i < input.size(); ++i) {
			pq.push(input[i]);

			if (pq.size() > k) {
				pq.pop();
			}
		}

		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top());
			pq.pop();
		}

		return vector<int>(res.rbegin(), res.rend());
	}
};