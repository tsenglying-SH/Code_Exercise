// Acwing requirement, solution via rbegin, rend
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	vector<int> printListReversingly(ListNode* head) {
		if (head == nullptr) {
			return{};
		}

		ListNode *node = head;
		vector<int> res;
		while (node != nullptr) {
			res.push_back(node->val);
			node = node->next;
		}
		return vector<int>(res.rbegin(), res.rend());
	}
};


// answer on the book, via stack
void PrintListReversingly_Iteratively(ListNode *pHead) {
	stack<int> nodes;
	ListNode *node = pHead;
	while (node != nullptr) {
		nodes.push(node->val);
		node = node->val;
	}

	while (!nodes.empty()) {
		node = nodes.top();
		cout << node->val << endl;
		node.pop();
	}
}

// answer on the book, via Recursion, if the list is long, it may cause stack overflow
void PrintListReversingly_Recursively(ListNode *pHead) {
	if (pHead != nullptr) {
		if (pHead->next != nullptr) {
			PrintListReversingly_Recursively(pHead->next);
		}
		cout << pHead->val << endl;
	}
}