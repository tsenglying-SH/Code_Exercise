/**
* Definition of ListNode
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*     ListNode(int val) {
*         this->val = val;
*         this->next = NULL;
*     }
* }
*/

//Priority Based Method
struct cmp {
	bool operator()(ListNode *a, ListNode *b) const {
		return a->val > b->val;
	}
};



class Solution {
public:
	/**
	* @param lists: a list of ListNode
	* @return: The head of one sorted list.
	*/
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		// write your code here
		if (lists.size() == 0) {
			return nullptr;
		}
		ListNode zero(0);
		ListNode *head = &zero;
		ListNode *pointer = head;

		priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != nullptr) {
				pq.push(lists[i]);
			}
		}

		while (!pq.empty()) {
			ListNode *node = pq.top(); pq.pop();
			pointer->next = node;
			pointer = pointer->next;
			ListNode *new_node = node->next;
			if (new_node != nullptr) {
				pq.push(new_node);
			}
		}
		return head->next;
	}
};


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
// merge in pairs method
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// write your code here
		if (lists.size() == 0) {
			return nullptr;
		}

		int amount = lists.size();
		int interval = 1;

		while (interval < amount) {
			for (int i = 0; i < amount - interval; i = i + 2 * interval) {
				lists[i] = merge2Lists(lists[i], lists[i + interval]);
			}
			interval *= 2;
		}
		return lists[0];
	}

	ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
		ListNode zero(0);
		ListNode *head = &zero;
		ListNode *point = head;

		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val <= l2->val) {
				point->next = l1;
				l1 = l1->next;
			}
			else {
				point->next = l2;
				l2 = l2->next;
			}
			point = point->next;
		}

		if (l1 == nullptr) {
			point->next = l2;
		}
		if (l2 == nullptr) {
			point->next = l1;
		}
		return head->next;
	}
};