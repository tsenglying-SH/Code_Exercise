// time O(n)
class Solution {
public:
	bool isPopOrder(vector<int> pushV, vector<int> popV) {
		// corner case
		if (pushV.empty() && popV.empty()) return true;
		if (pushV.size() != popV.size()) return false;
		stack<int> S;
		int idx_push = 0, idx_pop = 0;
		// if some elements hasn't been popped, do the loop
		while (idx_pop < popV.size()) {
			// if the elements to be pop not on the top of the stack, push somthing
			if (S.empty() || S.top() != popV[idx_pop]) {
				// all elements has been pushed in but top is not the elements to be popped, return false
				if (idx_push >= pushV.size()) return false;
				S.push(pushV[idx_push++]);
			}
			else {
				// element to be popped do on the top
				S.pop();
				idx_pop++;
			}
		}
		return true;
	}
};