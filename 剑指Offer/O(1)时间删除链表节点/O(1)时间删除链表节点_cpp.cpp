// to get whether the node is in the list, it have to take O(n), so here assume that the node to be deleted is really in the List.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v): val(v), next(nullptr){}
};

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted) {
	// corner case: invalid input
	if (pListHead == nullptr || pToBeDeleted == nullptr) {
		return
	}

	// if the node to be deleted is not the tail
	if (pToBeDeleted->next != nullptr) {
		ListNode *pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext; pNext = nullptr;
	}

	// the node is the tail, and it's the only one node in the List
	else if (*pListHead == pToBeDeleted) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		// don't forget put the head to nullptr, or maybe delete twice
		*pListHead = nullptr;
	}
	// if the node is the tail and it's not the only one node in the List
	else {
		ListNode *pPre = *pListHead;
		while (pPre->next != pToBeDeleted) {
			pPre = pPre->next;
		}
		pPre->next = nullptr;
		delete pToBeDeleted; pToBeDeleted = nullptr;
	}
}
