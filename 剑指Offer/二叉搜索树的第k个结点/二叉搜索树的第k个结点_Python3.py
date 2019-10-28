# -*- coding: utf-8 -*-
"""
Created on Mon Oct 28 19:28:29 2019

@author: 84685
"""

# iterative method
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthNode(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: TreeNode
        """
        if not root: return
        S = []
        p = root
        res = None
        while k:
            while p:
                S.append(p)
                p = p.left
            
            if not S: return
            p = S.pop()
            res = p
            p = p.right
            k -= 1
        return res
    
    
# Recursive method
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthNode(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: TreeNode
        """
        if not root: return
        self.res = None
        self.k = k
        self.dfs(root, self.k)
        return self.res
    
    def dfs(self, root, k):
        if not root: return
        self.dfs(root.left, self.k)
        self.k -= 1
        if self.k == 0: self.res = root
        if self.k > 0: self.dfs(root.right, self.k)