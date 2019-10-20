# -*- coding: utf-8 -*-
"""
Created on Sun Oct 20 12:43:35 2019

@author: 84685
"""

# Definition for singly-linked list with a random pointer.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#         self.random = None

# hash table method, time O(n), space O(n)
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return
        old_to_new = {}
        dummy = ListNode(-1)
        p1 = head
        p2 = ListNode(p1.val)
        dummy.next = p2
        
        while p1:
            p2.val = p1.val
            old_to_new[p1] = p2
            if p1.next:
                p2.next = ListNode(p1.next.val)
                p1 = p1.next
                p2 = p2.next
            else:
                break
        p1 = head
        p2 = dummy.next
        while p1:
            if p1.random:
                p2.random = old_to_new[p1.random]
            p1 = p1.next
            p2 = p2.next
        return dummy.next
    
# tricky method, time O(n), space O(1)
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # corner case
        if not head: return
        
        # insert copy into original list
        p1 = head
        while p1:
            p2 = ListNode(p1.val)
            p2.next = p1.next
            p1.next = p2
            p1 = p2.next
        
        # build random link
        p1 = head
        while p1:
            if p1.random:
                p1.next.random = p1.random.next
            p1 = p1.next.next
        
        # split the list into 2 lists, 1 original list and 1 new list
        p1 = head
        dummy = ListNode(-1)
        cur = dummy
        while p1:
            cur.next = p1.next
            cur = cur.next
            p1.next = p1.next.next
            p1 = p1.next
        return dummy.next