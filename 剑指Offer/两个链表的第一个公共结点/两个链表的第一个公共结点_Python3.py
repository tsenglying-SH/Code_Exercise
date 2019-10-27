# -*- coding: utf-8 -*-
"""
Created on Sun Oct 27 14:44:02 2019

@author: 84685
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# tricky traverse, time O(m + n), space O(1)
class Solution(object):
    def findFirstCommonNode(self, headA, headB):
        """
        :type headA, headB: ListNode
        :rtype: ListNode
        """
        if  not headA or not headB: return
        pA, pB = headA, headB
        toB, toA = True, True
        
        while pA != pB:
            if not pA.next and toB:
                pA = headB
                toB = False
            else:
                pA = pA.next
            
            if not pB.next and toA:
                pB = headA
                toA = False
            else:
                pB = pB.next
        
        return pA