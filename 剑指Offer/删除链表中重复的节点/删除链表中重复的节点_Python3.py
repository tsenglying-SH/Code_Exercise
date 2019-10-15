# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""

# time O(n)
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplication(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return
        
        if not head.next:
            return head
        
        dummy = ListNode(-1)
        dummy.next = head
        cur = dummy
        while cur.next:
            post = cur.next
            # go ahead until post's value different from cur's or post is nullptr
            while post and post.val == cur.next.val:
                post = post.next
            # check if the number of nodes between cur and post is 1.
            if cur.next.next == post:
                cur = cur.next
            # if not, skip them.
            else:
                cur.next = post
                
        return dummy.next