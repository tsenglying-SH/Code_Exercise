# -*- coding: utf-8 -*-
"""
Created on Fri Oct 18 18:21:12 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# time O(n)
class Solution(object):
    def mirror(self, root):
        """
        :type root: TreeNode
        :rtype: void
        """
        if not root:
            return
        
        tmp = root.left
        root.left = root.right
        root.right = tmp
        
        self.mirror(root.left)
        self.mirror(root.right)