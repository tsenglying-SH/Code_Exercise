// deque method, time O(n), space O(k)
class Solution {
public:
	vector<int> maxInWindows(vector<int>& nums, int k) {
		// corner case
		if (nums.empty() || k <= 0 || nums.size() < k) return{};
		vector<int> res;
		deque<int> win_of_idx;
		for (int i = 0; i < nums.size(); ++i) {
			// if the front is out of window range, delete it
			while (!win_of_idx.empty() && win_of_idx.front() + k - 1 < i) win_of_idx.pop_front();
			// if the back is defeated by the new one, delete it
			while (!win_of_idx.empty() && nums[i] >= nums[win_of_idx.back()]) win_of_idx.pop_back();
			// add the new one
			win_of_idx.push_back(i);
			// record the current maximum
			if (i >= k - 1) res.push_back(nums[win_of_idx.front()]);
		}
		return res;
	}
};