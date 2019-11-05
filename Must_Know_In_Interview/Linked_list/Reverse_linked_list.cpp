/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

// iterative method, time O(n)
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *pre = nullptr, *cur = head;
		while (cur) {
			ListNode *post = cur->next;
			cur->next = pre;
			pre = cur;
			cur = post;
		}
		return pre;
	}
};

// Recursive method, time O(n)
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *node = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return node;
	}
};