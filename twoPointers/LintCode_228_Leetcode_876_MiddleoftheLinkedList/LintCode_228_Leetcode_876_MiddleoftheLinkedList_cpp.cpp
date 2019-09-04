/**
* Definition of singly-linked-list:
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*     ListNode(int val) {
*        this->val = val;
*        this->next = NULL;
*     }
* }
*/

// Fast slow pointer time O(n)
class Solution {
public:
	/**
	* @param head: the head of linked list.
	* @return: a middle node of the linked list
	*/
	ListNode * middleNode(ListNode * head) {
		// write your code here
		if (head == nullptr) {
			return nullptr;
		}

		ListNode *slow = head;
		ListNode *fast = head;

		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		 // Lintcode call for the left one if there are even list in the list
		return slow;

	}
};

// Fast slow pointer time O(n)
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
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}

		ListNode *fast = head;
		ListNode *slow = head;

		while (fast->next != nullptr && fast->next->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}

		// Leetcode call for the right one if there are even list in the list
		if (fast->next != nullptr) {
			slow = slow->next;
		}

		return slow;
	}
};