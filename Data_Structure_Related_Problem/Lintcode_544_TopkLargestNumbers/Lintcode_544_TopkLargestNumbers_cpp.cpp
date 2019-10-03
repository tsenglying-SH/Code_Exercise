// priority queue based method
class Solution {
public:
	/**
	* @param nums: an integer array
	* @param k: An integer
	* @return: the top k largest numbers in array
	*/
	vector<int> topk(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty() || k <= 0) {
			return{};
		}
		// greater - minheap, less - maxheap, default -  maxheap
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int num : nums) {
			pq.push(num);
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


// quick select based method, time O(n + klogk)
bool cmp(const int &a, const int &b) {
	return a > b;
}

class Solution {
private:
	vector<int> res;

public:
	/**
	* @param nums: an integer array
	* @param k: An integer
	* @return: the top k largest numbers in array
	*/
	vector<int> topk(vector<int> &nums, int k) {
		// write your code here
		if (nums.empty() || k <= 0) {
			return{};
		}
		partition(nums, k, 0, nums.size() - 1);
		sort(res.begin(), res.end(), cmp);
		return res;
	}

	void partition(vector<int> &nums, int k, int start, int end) {
		if (start > end || k <= 0) {
			return;
		}

		if (start == end && k == 1) {
			res.push_back(nums[start]);
			return;
		}

		int l = start, r = end;
		int mid = l + (r - l) / 2;
		int pivot = nums[mid];

		while (l <= r) {
			while (l <= r && nums[l] > pivot) {
				l++;
			}
			while (l <= r && nums[r] < pivot) {
				r--;
			}
			if (l <= r) {
				swap(nums[l++], nums[r--]);
			}
		}

		if (start + k - 1 <= r) {
			partition(nums, k, start, r);
		}
		else if (start + k - 1 >= l) {
			res.insert(res.end(), nums.begin() + start, nums.begin() + l);
			partition(nums, k - l + start, l, end);
		}
		else {
			res.insert(res.end(), nums.begin() + start, nums.begin() + l);
		}
	}
};
