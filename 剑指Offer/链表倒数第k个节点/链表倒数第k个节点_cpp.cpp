// traverse 2 times, time O(n)
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
	ListNode* findKthToTail(ListNode* pListHead, int k) {
		// corner case 1
		if (k <= 0) {
			return nullptr;
		}

		// corner case 2
		if (pListHead == nullptr) {
			return nullptr;
		}

		ListNode *pLen_count = pListHead;
		int length = 1;
		while (pLen_count->next) {
			length++;
			pLen_count = pLen_count->next;
		}

		// corner case 3, list is not long enough
		if (length < k) {
			return nullptr;
		}
		int step = length - k;
		pLen_count = pListHead;
		while (step--) {
			pLen_count = pLen_count->next;
		}
		return pLen_count;
	}
};

// traverse 1 times, fast slow pointers, time O(n)
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
	ListNode* findKthToTail(ListNode* pListHead, int k) {
		// 2 corner cases
		if (k <= 0 || pListHead == nullptr) {
			return nullptr;
		}
		// set two fast, slow pointers
		ListNode *p_fast = pListHead, *p_slow = pListHead;
		int fast_step = k - 1;

		// fast pointers go k - 1 steps first
		for (int i = 1; i <= fast_step; ++i) {
			// the 3rd corner case
			if (p_fast->next == nullptr) {
				return nullptr;
			}
			p_fast = p_fast->next;
		}

		// then fast, slow pointers go together, when fast pointers is the tail of the List, return the slow pointer
		while (p_fast->next) {
			p_slow = p_slow->next;
			p_fast = p_fast->next;
		}
		return p_slow;
	}
};