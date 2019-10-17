# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def entryNodeOfLoop(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # corner case, empty List or one-node List
        if not head or not head.next:
            return
        
        p_fast = p_slow = head
        enter = True
        # In the first rouond, fast pointer takes 2 steps everytime and slow pointer 1
		# Imagine that the entrance x steps far from the head, and the 
        # meeting point y steps far from the entrance. 
		# Then it can be calculated that x + y = k * (circle * pi * d), 
        # take more x step from the meeting point, and the pointers will reach the entrance.
		# On the other hand, the entrace is x step far from the head, too. 
        # So let one pointer start from the head and another from the meeting point, 
        # step x steps and reach the entrance.
        while enter or p_fast != p_slow:
            enter = False
            fast_step = 2
            for _ in range(fast_step):
                p_fast = p_fast.next
                # if p_fast reach the tail of the List, no loop exists, return nullptr.
                if not p_fast: return
            p_slow = p_slow.next
        
        # In the second rouond, the pointers both take 1 step every time.
        p_slow = head
        while p_slow != p_fast:
            p_slow = p_slow.next
            p_fast = p_fast.next
        return p_fast
    
