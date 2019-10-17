/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
// time O(n), space O(1)
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}

		if (head->next == nullptr) {
			return head;
		}

		ListNode *pre = nullptr, *cur = head, *post = head->next;

		while (post) {
			cur->next = pre;
			pre = cur;
			cur = post;
			post = post->next;
		}
		cur->next = pre;
		return cur;
	}
};

// code above can be simplified
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *pre = nullptr;
		while (head) {
			ListNode *post = head->next;
			head->next = pre;
			pre = head;
			head = post;
		}
		return pre;
	}
};