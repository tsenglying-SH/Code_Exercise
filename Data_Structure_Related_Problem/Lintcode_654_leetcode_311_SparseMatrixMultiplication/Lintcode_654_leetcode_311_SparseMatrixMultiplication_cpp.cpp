// Naive way, time O(n^3)
class Solution {
public:
	/**
	* @param A: a sparse matrix
	* @param B: a sparse matrix
	* @return: the result of A * B
	*/
	vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
		// write your code here
		if (A.empty() || B.empty() || A[0].size() != B.size()) {
			return{};
		}

		int m = A.size(), n = A[0].size(), p = B[0].size();
		vector<vector<int>> res(m, vector<int>(p, 0));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < p; ++j) {
				for (int k = 0; k < n; ++k) {
					res[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		return res;
	}
};

// take A's sparse into acount, time O(ka * n^3)
class Solution {
public:
	/**
	* @param A: a sparse matrix
	* @param B: a sparse matrix
	* @return: the result of A * B
	*/
	vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
		// write your code here
		if (A.empty() || B.empty() || A[0].size() != B.size()) {
			return{};
		}

		int m = A.size(), n = A[0].size(), p = B[0].size();
		vector<vector<int>> res(m, vector<int>(p, 0));

		for (int i = 0; i < m; ++i) {
			for (int k = 0; k < n; ++k) {
				// skip some useless calculation, when A's element is 0.
				if (A[i][k] != 0) {
					for (int j = 0; j < p; ++j) {
						res[i][j] += A[i][k] * B[k][j];
					}
				}
			}
		}

		return res;
	}
};


// take A and B's sparse into acount, time O(ka * kb * n^3)
class Solution {
public:
	/**
	* @param A: a sparse matrix
	* @param B: a sparse matrix
	* @return: the result of A * B
	*/
	vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
		// write your code here
		if (A.empty() || B.empty() || A[0].size() != B.size()) {
			return{};
		}

		int m = A.size(), n = A[0].size(), p = B[0].size();
		vector<vector<int>> A_non_zero, B_non_zero;
		vector<vector<int>> res(m, vector<int>(p, 0));

		// save the nonzero coordinate
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (A[i][j] != 0) {
					A_non_zero.push_back({ i, j });
				}
			}
		}
		// save the nonzero coordinate
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < p; ++j) {
				if (B[i][j] != 0) {
					B_non_zero.push_back({ i, j });
				}
			}
		}

		// calculate the result
		for (auto ax_ay : A_non_zero) {
			for (auto bx_by : B_non_zero) {
				if (ax_ay[1] == bx_by[0]) {
					res[ax_ay[0]][bx_by[1]] += A[ax_ay[0]][ax_ay[1]] * B[bx_by[0]][bx_by[1]];
				}
			}
		}

		return res;
	}
};