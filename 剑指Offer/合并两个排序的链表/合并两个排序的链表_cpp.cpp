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
	ListNode* merge(ListNode* l1, ListNode* l2) {
		if (!l1 && !l2) { return nullptr; }
		if (!l1) { return l2; }
		if (!l2) { return l1; }
		ListNode *dummy = new ListNode(0), *node = dummy;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				node->next = l1;
				l1 = l1->next;
			}
			else {
				node->next = l2;
				l2 = l2->next;
			}
			node = node->next;
		}
		if (l1) {
			node->next = l1;
		}
		else if (l2) {
			node->next = l2;
		}
		l1 = dummy->next;
		// release some memory and avoid delete twice
		delete dummy; dummy = nullptr;
		return l1;
	}
};