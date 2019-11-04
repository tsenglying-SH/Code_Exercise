// leecode 658, lintcode 460, binary search then linear search
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		if (arr.empty() || k <= 0 || k > arr.size()) return{};
		int l = 0, r = arr.size() - 1;

		while (l + 1 < r) {
			int mid = l + (r - l) / 2;
			if (arr[mid] >= x) r = mid;
			else l = mid;
		}

		vector<int> res(k, 0);
		for (int i = 0; i < k; ++i) {
			if (l < 0) res[i] = arr[r++];
			else if (r > arr.size() - 1) res[i] = arr[l--];
			else {
				res[i] = x - arr[l] <= arr[r] - x ? arr[l--] : arr[r++];
			}
		}
		sort(res.begin(), res.end());
		return res;
	}
};