# -*- coding: utf-8 -*-
"""
Created on Sat Oct 12 19:59:32 2019

@author: 84685
"""

# Acwing requirement
class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None

def printListReversingly(head):
    """
    :type head: ListNode
    :rtype: List[int]
    """
    if not head:
        return []
    
    res = []
    node = head
    while node:
        res.append(node.val)
        node = node.next
    
    return res[::-1]

# book requirement
# via stack
def printListReversingly_iteratively(head):
    stack = []
    node = head
    while node:
        stack.append(node)
        node = node.next
    
    while stack:
        node = stack.pop()
        print(node.val)

# via recursion, may cause stack overflow when the list is long
def printListReversingly_recursively(head):
    if head:
        if head.next:
            printListReversingly_recursively(head.next)
        print(head.val)