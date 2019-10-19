# -*- coding: utf-8 -*-
"""
Created on Sat Oct 19 17:25:37 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def printFromTopToBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
            
        queue = deque([root])
        res = []
        while queue:
            node = queue.popleft()
            res.append(node.val)
            
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
        return res