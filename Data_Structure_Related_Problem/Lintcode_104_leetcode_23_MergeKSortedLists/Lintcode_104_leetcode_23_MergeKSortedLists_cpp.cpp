//heap Based Method, time O(nlogk), space O(k)

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct cmp {
	bool operator()(const ListNode *a, const ListNode *b) {
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return nullptr;
		}
		// overload cmp
		priority_queue<ListNode *, vector<ListNode*>, cmp> pq;

		for (ListNode *tail : lists) {
			// ensure the node is valid
			if (tail != nullptr) {
				pq.push(tail);
			}
		}

		ListNode *dummy = new ListNode(0);
		ListNode *root = dummy;

		while (!pq.empty()) {
			ListNode *node = pq.top(); pq.pop();
			if (node->next != nullptr) {
				pq.push(node->next);
			}

			root->next = node;
			root = root->next;
		}
		return dummy->next;
	}
};

// Merge Lists in pairs, using Recursion, time O(nlogk), space O(logk) (due to recursion)
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return nullptr;
		}
		return helper(lists, 0, lists.size() - 1);
	}

	ListNode* helper(vector<ListNode*> &lists, int start, int end) {
		if (start > end) {
			return nullptr;
		}
		if (start == end) {
			return lists[start];
		}

		int mid = start + (end - start) / 2;
		ListNode *left = helper(lists, start, mid);
		ListNode *right = helper(lists, mid + 1, end);

		return merge2lists(left, right);
	}

	ListNode* merge2lists(ListNode* tail1, ListNode* tail2) {
		if (tail1 == nullptr) {
			return tail2;
		}
		if (tail2 == nullptr) {
			return tail1;
		}

		ListNode* dummy = new ListNode(0);
		ListNode* root = dummy;

		while (tail1 != nullptr && tail2 != nullptr) {
			if (tail1->val <= tail2->val) {
				root->next = tail1;
				root = root->next;
				tail1 = tail1->next;
			}
			else {
				root->next = tail2;
				root = root->next;
				tail2 = tail2->next;
			}
		}
		if (tail1 != nullptr) {
			root->next = tail1;
		}

		if (tail2 != nullptr) {
			root->next = tail2;
		}

		return dummy->next;
	}
};

// Merge Lists in pairs, time O(nlogk), space O(1)
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return nullptr;
		}

		int interval = 1;
		int amount = lists.size();
		while (amount > interval) {
			for (int i = 0; i + interval < amount; i += 2 * interval) {
				lists[i] = merge2Lists(lists[i], lists[i + interval]);
			}
			interval *= 2;
		}

		return lists[0];
	}

	ListNode* merge2Lists(ListNode* tail1, ListNode* tail2) {
		if (tail1 == nullptr) {
			return tail2;
		}
		if (tail2 == nullptr) {
			return tail1;
		}

		ListNode* dummy = new ListNode(0);
		ListNode* root = dummy;

		while (tail1 != nullptr && tail2 != nullptr) {
			if (tail1->val <= tail2->val) {
				root->next = tail1;
				root = root->next;
				tail1 = tail1->next;
			}
			else {
				root->next = tail2;
				root = root->next;
				tail2 = tail2->next;
			}
		}

		if (tail1 != nullptr) {
			root->next = tail1;
		}
		if (tail2 != nullptr) {
			root->next = tail2;
		}

		return dummy->next;
	}
};