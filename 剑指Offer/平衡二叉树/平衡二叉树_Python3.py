# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 20:58:43 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Recursive Method
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root: return True
        return self.depth(root) != -1
    
    def depth(self, root):
        if not root: return 0
        h_left = self.depth(root.left)
        h_right = self.depth(root.right)
        if abs(h_left - h_right) > 1 or h_left == -1 or h_right == -1:
            return -1
        return max(h_left, h_right) + 1