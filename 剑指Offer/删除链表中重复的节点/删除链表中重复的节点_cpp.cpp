// time O(n)
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(nullptr){}
};

ListNode *deleteDuplication(ListNode *head) {
	if (!head) {
		return nullptr;
	}
	if (!head->next) {
		return head;
	}

	ListNode *dummy = new ListNode(-1), *cur = dummy;
	dummy->next = head;
	while (cur->next) {
		ListNode *post = cur->next;
		// go ahead until post's value different from cur's or post is nullptr
		while (post && post->val == cur->next->val) { post = post->next; }
		// check if the number of nodes between cur and post is 1.
		if (cur->next->next == post) {
			cur = cur->next;
		}
		// if not, skip them.
		else {
			cur->next = post;
		}
	}
	return dummy->next;
}