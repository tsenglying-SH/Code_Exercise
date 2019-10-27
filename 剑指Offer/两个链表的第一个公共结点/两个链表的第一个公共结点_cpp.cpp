// tricky traverse, time O(m + n), space O(1)
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
	ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return nullptr;
		ListNode *pA = headA, *pB = headB;
		bool toB = true, toA = true;
		while (pA != pB) {
			if (!pA->next && toB) pA = headB, toB = false;
			else pA = pA->next;
			if (!pB->next && toA) pB = headA, toA = false;
			else pB = pB->next;
		}
		return pA;
	}
};