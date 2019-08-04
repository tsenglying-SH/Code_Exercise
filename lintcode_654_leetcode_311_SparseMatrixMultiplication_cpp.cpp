class Solution {
public:
	/**
	* @param A: a sparse matrix
	* @param B: a sparse matrix
	* @return: the result of A * B
	*/
	vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
		// write your code here
		int ma = A.size();
		int na = A[0].size();
		int mb = B.size();
		int nb = B[0].size();

		vector<vector<int>> C(ma, vector<int>(nb, 0));

		vector<pair<int, int>> A_not_zero;
		for (int i = 0; i < ma; i++) {
			for (int j = 0; j < na; j++) {
				if (A[i][j] != 0) {
					A_not_zero.push_back({ i, j });
				}
			}
		}

		vector<pair<int, int>> B_not_zero;
		for (int i = 0; i < mb; i++) {
			for (int j = 0; j < nb; j++) {
				if (B[i][j] != 0) {
					B_not_zero.push_back({ i, j });
				}
			}
		}

		for (auto a_pair : A_not_zero) {
			for (auto b_pair : B_not_zero) {
				if (a_pair.second == b_pair.first) {
					C[a_pair.first][b_pair.second] += A[a_pair.first][a_pair.second] * B[b_pair.first][b_pair.second];
				}
			}
		}
		return C;
	}
};