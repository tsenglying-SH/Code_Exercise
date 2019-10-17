/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
// time O(n)
class Solution {
public:
	ListNode *entryNodeOfLoop(ListNode *head) {
		// corner case, empty List or one-node List
		if (!head || !head->next) { return nullptr; }
		ListNode *p_fast = head, *p_slow = head;
		bool enter = true;
		// In the first rouond, fast pointer takes 2 steps everytime and slow pointer 1
		// Imagine that the entrance x steps far from the head, and the  meeting point y steps far from the entrance. 
		// Then it can be calculated that x + y = k * (circle * pi * d), take more x step from the meeting point, and the pointers will reach the entrance.
		// On the other hand, the entrace is x step far from the head, too. So let one pointer start from the head and another from the meeting point, step x steps and reach the entrance.
		while (enter || p_fast != p_slow) {
			enter = false;
			int fast_step = 2;
			while (fast_step--) {
				p_fast = p_fast->next;
				// if p_fast reach the tail of the List, no loop exists, return nullptr.
				if (!p_fast->next) { return nullptr; }
			}
			p_slow = p_slow->next;
		}
		// In the second rouond, the pointers both take 1 step every time.
		p_slow = head;
		while (p_slow != p_fast) {
			p_slow = p_slow->next;
			p_fast = p_fast->next;
		}
		return p_fast;
	}
};