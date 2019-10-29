# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 20:50:03 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Recursive method
class Solution:
    def treeDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        return max(self.treeDepth(root.left), self.treeDepth(root.right)) + 1