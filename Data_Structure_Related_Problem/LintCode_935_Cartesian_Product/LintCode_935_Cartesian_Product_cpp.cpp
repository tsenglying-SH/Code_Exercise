// DFS for Cartesian_Product
class Solution {
public:
	/**
	* @param setList: The input set list
	* @return: the cartesian product of the set list
	*/
	vector<vector<int>> getSet(vector<vector<int>> &setList) {
		// Write your code here
		if (setList.empty()) {
			return{};
		}
		int max_step = setList.size();
		vector<int> path;
		vector<vector<int>> res;
		dfs(setList, 0, max_step, path, res);
		return res;
	}

	void dfs(const vector<vector<int>> &setList, int cur_step, int max_step,
		vector<int> &path, vector<vector<int>> &res) {
		if (cur_step == max_step) {
			res.push_back(path);
			return;
		}
		if (cur_step > max_step) {
			return;
		}

		for (int element : setList[cur_step]) {
			path.push_back(element);
			dfs(setList, cur_step + 1, max_step, path, res);
			path.pop_back();
		}
	}
};