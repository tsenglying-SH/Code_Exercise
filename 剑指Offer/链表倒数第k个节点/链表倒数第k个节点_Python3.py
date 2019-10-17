# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""

# Solution 1: traverse 2 times, time O(n)
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def findKthToTail(self, pListHead, k):
        """
        :type pListHead: ListNode
        :type k: int
        :rtype: ListNode
        """
        # corner case1
        if k <= 0:
            return 
        # corner case2
        if not pListHead:
            return
        
        pHelp = pListHead
        length = 1
        while pHelp.next:
            length += 1
            pHelp = pHelp.next
        
        # corner case 3, List is not long enough
        if length < k:
            return
        
        pHelp = pListHead
        step = length - k
        while step:
            pHelp = pHelp.next
            step -= 1
        return pHelp
    

# traverse 1 times, fast slow pointers, time O(n)
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def findKthToTail(self, pListHead, k):
        """
        :type pListHead: ListNode
        :type k: int
        :rtype: ListNode
        """
        # 2 corner cases
        if not pListHead or k <= 0:
            return
        
        # set two fast, slow pointers
        p_fast = p_slow = pListHead
        
        # fast pointers go k - 1 steps first
        for _ in range(k - 1):
            # the 3rd corner case
            if not p_fast.next:
                return
            p_fast = p_fast.next
        
        # then fast, slow pointers go together, 
        # when fast pointers is the tail of the List, return the slow pointer
        while p_fast.next:
            p_slow = p_slow.next
            p_fast = p_fast.next
        
        return p_slow
    
