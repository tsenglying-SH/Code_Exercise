# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# time O(mn)
class Solution(object):
    def hasSubtree(self, pRoot1, pRoot2):
        """
        :type pRoot1: TreeNode
        :type pRoot2: TreeNode
        :rtype: bool
        """
        if not pRoot1 or not pRoot2: return False
        if self.match(pRoot1, pRoot2): return True
        return self.hasSubtree(pRoot1.left, pRoot2) or self.hasSubtree(pRoot1.right, pRoot2)
        
    def match(self, node1, node2):
        if not node2: return True
        if not node1 or node1.val != node2.val: return False
        return self.match(node1.left, node2.left) and self.match(node1.right, node2.right)
