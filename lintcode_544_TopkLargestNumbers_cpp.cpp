// priority queue based method

bool cmp(const int &a, const int &b) {
	return a > b;
}
class Solution {
public:
	/**
	* @param nums: an integer array
	* @param k: An integer
	* @return: the top k largest numbers in array
	*/


	vector<int> topk(vector<int> &nums, int k) {
		// write your code here
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < nums.size(); i++) {
			pq.push(nums[i]);
			if (pq.size() > k) {
				pq.pop();
			}
		}

		vector<int> res;
		while (pq.size() > 0) {
			res.push_back(pq.top());
			pq.pop();
		}

		sort(res.begin(), res.end(), cmp);
		return res;
	}

};


// quick select based method
bool cmp(const int &a, const int &b) {
	return a > b;
}

class Solution {
public:
	/**
	* @param nums: an integer array
	* @param k: An integer
	* @return: the top k largest numbers in array
	*/
	vector<int> topk(vector<int> &nums, int k) {
		// write your code here
		vector<int> res;
		helper(nums, k, 0, nums.size() - 1, res);
		sort(res.begin(), res.end(), cmp);
		return res;
	}

	void helper(vector<int> &nums, int k, int start, int end, vector<int> &res) {
		if (start >  end) {
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
				swap(nums[l], nums[r]);
				l++;
				r--;
			}
		}
		if (start + k - 1 <= r) {
			helper(nums, k, start, r, res);
			return;
		}
		else if (start + k - 1 >= l) {
			res.insert(res.end(), nums.begin() + start, nums.begin() + l);
			helper(nums, k - l + start, l, end, res);
			return;
		}
		else {
			res.insert(res.end(), nums.begin() + start, nums.begin() + l);
			return;
		}
	}
};
