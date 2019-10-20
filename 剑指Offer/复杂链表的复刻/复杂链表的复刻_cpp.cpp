/**
* Definition for singly-linked list with a random pointer.
* struct ListNode {
*     int val;
*     ListNode *next, *random;
*     ListNode(int x) : val(x), next(NULL), random(NULL) {}
* };
*/

// hash method, time O(n), space O(n)
class Solution {
public:
	ListNode *copyRandomList(ListNode *head) {
		// corner case
		if (!head) return nullptr;

		ListNode *dummy = new ListNode(0);
		ListNode *p1 = head, *p2 = new ListNode(p1->val);
		dummy->next = p2;
		unordered_map<ListNode *, ListNode *> old_to_new;

		while (p1) {
			p2->val = p1->val;
			old_to_new[p1] = p2;
			if (p1->next) {
				p2->next = new ListNode(p1->next->val);
				p1 = p1->next;
				p2 = p2->next;
			}
			else {
				break;
			}
		}
		p1 = head, p2 = dummy->next;

		while (p1) {
			if (!p1->random) {
				p2->random = nullptr;
			}
			else {
				p2->random = old_to_new[p1->random];
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return dummy->next;
	}
};


// tricky method, time O(n), space O(1)
class Solution {
public:
	ListNode *copyRandomList(ListNode *head) {
		// corner case
		if (!head) return nullptr;
		
		// insert copy into original list
		ListNode *p1 = head;
		while (p1) {
			ListNode *p2 = new ListNode(p1->val);
			p2->next = p1->next;
			p1->next = p2;
			p1 = p2->next;
		}
		// build the random link
		p1 = head;
		while (p1) {
			if (p1->random) {
				p1->next->random = p1->random->next;
			}
			p1 = p1->next->next;
		}
		// split the list into 2 list, 1 original list and 1 new list
		p1 = head;
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		while (p1) {
			cur->next = p1->next;
			cur = cur->next;
			p1->next = p1->next->next;
			p1 = p1->next;
		}
		ListNode *p2 = dummy->next;
		delete dummy; dummy = nullptr;
		return p2;
	}
};
