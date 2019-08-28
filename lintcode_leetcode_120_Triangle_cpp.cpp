// dp method time O(n^2), space O(n)
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty() || triangle.back().empty()) {
			return 0;
		}

		int n = triangle.size();
		vector<int> dp_array(n, INT_MAX);
		dp_array[0] = triangle[0][0];

		for (int i = 1; i < n; i++) {
			dp_array[i] = triangle[i][i] + dp_array[i - 1];
			for (int j = i - 1; j > 0; j--) {
				int left = dp_array[j - 1] + triangle[i][j];
				int right = dp_array[j] + triangle[i][j];
				dp_array[j] = min(left, right);
			}
			dp_array[0] += triangle[i][0];
		}
		int result = INT_MAX;
		for (int &num : dp_array) {
			if (num < result) {
				result = num;
			}
		}
		return result;
	}
};