# -*- coding: utf-8 -*-
"""
Created on Sat Oct 19 20:00:17 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findPath(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root: return []
        path = []
        res = []
        self.dfs(root, path, res, sum)
        return res
    
    def dfs(self, node, path, res, sum):
        if not node: return
        
        path.append(node.val)
        sum -= node.val
        
        if not node.left and not node.right and sum == 0:
            res.append(path[:])
            # back tracking if return
            path.pop()
            return
        if sum <= 0:
            # back tracking if return
            path.pop()
            return
        
        self.dfs(node.left, path, res, sum)
        self.dfs(node.right, path, res, sum)
        # back tracking if return
        path.pop()
        