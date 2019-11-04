// List merge sort template
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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = nullptr;

		return merge(sortList(head), sortList(fast));
	}

	ListNode* merge(ListNode* node1, ListNode *node2) {
		if (!node1) return node2;
		if (!node2) return node1;

		ListNode *dummy = new ListNode(0), *p = dummy;

		while (node1 && node2) {
			if (node1->val <= node2->val) p->next = node1, node1 = node1->next;
			else p->next = node2, node2 = node2->next;
			p = p->next;
		}

		if (node1) p->next = node1;
		if (node2) p->next = node2;

		p = dummy->next;
		delete dummy; dummy = nullptr;
		return p;
	}
};


// the mergesort below, dummy is a ListNode not a pointer, and at the end of merge, we don't do delete, it may be faster and save more space on the OJ 
// but I think the method above is better
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = nullptr;

		return merge(sortList(head), sortList(fast));
	}

	ListNode* merge(ListNode* node1, ListNode *node2) {
		if (!node1) return node2;
		if (!node2) return node1;

		ListNode dummy = ListNode(0), *p = &dummy;

		while (node1 && node2) {
			if (node1->val <= node2->val) p->next = node1, node1 = node1->next;
			else p->next = node2, node2 = node2->next;
			p = p->next;
		}

		if (node1) p->next = node1;
		if (node2) p->next = node2;

		return dummy.next;
	}
};


// Quick Sort template, worst case O(n^2), fortunately O(nlogn)
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		// notice left closed interval, right open interval
		partition(head, nullptr);
		return head;
	}

	void partition(ListNode *head, ListNode *end) {
		if (head == end || head->next == end) return;
		int pivot = head->val;
		ListNode *p = head, *q = head->next;

		while (q != end) {
			if (q->val < pivot) {
				p = p->next;
				swap(p->val, q->val);
			}
			q = q->next;
		}

		swap(head->val, p->val);

		partition(head, p);
		// to finish the recurion, p->next is necessary
		partition(p->next, end);
	}
};