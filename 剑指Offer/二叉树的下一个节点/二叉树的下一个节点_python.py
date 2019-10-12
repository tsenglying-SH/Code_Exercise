# -*- coding: utf-8 -*-
"""
Created on Sat Oct 12 19:59:32 2019

@author: 84685
"""
# nothing special haha, it's easy, if we have father information of nodes

# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.father = None

def inorderSuccessor(q):
    """
    :type q: TreeNode
    :rtype: TreeNode
    """
    if not q:
        return 
    
    if q.right:
        q = q.right
        while q.left:
            q = q.left
        return q
    else:
        while q.father and q.father.right == q:
            q = q.father
        # it'll be next node or null
        return q.father