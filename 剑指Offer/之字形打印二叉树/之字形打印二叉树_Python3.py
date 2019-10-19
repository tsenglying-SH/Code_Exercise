# -*- coding: utf-8 -*-
"""
Created on Sat Oct 19 17:53:14 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution(object):
    def printFromTopToBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        queue = deque([root])
        res = []
        reverse = False
        while queue:
            size = len(queue)
            level = []
            
            for _ in range(size):
                node = queue.popleft()
                level.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            
            if reverse:
                res.append(level[::-1])
                reverse = False
            else:
                res.append(level)
                reverse = True
        return res