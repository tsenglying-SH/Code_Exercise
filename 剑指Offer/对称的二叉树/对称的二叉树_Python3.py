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

# Recursive method
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # empty is symmetric
        if not root:
            return True
        # check left son and right son's value is the same.
        return self.dfs(root.left, root.right)
    
    def dfs(self, node1, node2):
        if not node1 or not node2: return not node1 and not node2
        # recursive check the sons of son
        return node1.val == node2.val and self.dfs(node1.left, node2.right) and \
        self.dfs(node1.right, node2.left)
        
        
# Iterative method
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root: return True
        p_left = p_right = root
        s1, s2 = [], []
        while p_left:
            s1.append(p_left)
            p_left = p_left.left
        while p_right:
            s2.append(p_right)
            p_right = p_right.right
        if len(s1) != len(s2): return False
        p_left, p_right = s1[-1], s2[-1]
        
        while p_left != root and p_right !=root:
            p_left, p_right = p_left.right, p_right.left
            while p_left:
                s1.append(p_left)
                p_left = p_left.left
            while p_right:
                s2.append(p_right)
                p_right = p_right.right
            
            p_left, p_right = s1.pop(), s2.pop()
            if p_left.val != p_right.val: return False
        
        return True