# -*- coding: utf-8 -*-
"""
Created on Sun Oct 20 14:10:45 2019

@author: 84685
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# original method myself, time O(nlogn)
class Solution(object):
    def convert(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root: return
        node = self.dfs(root)
        while (node.left):
            node = node.left
        return node
    
    def dfs(self, node):
        if not node: return
        if not node.left and not node.right: return node
        
        left = self.dfs(node.left)
        if left:
            while left.right:
                left = left.right
            left.right = node
        node.left = left
        
        right = self.dfs(node.right)
        if right:
            while right.left:
                right = right.left
            right.left = node
        node.right = right
        return node
    
    
# Acwing solution, time O(n), the move in the above is not necessary, we only
# care about the bound of the interval.
class Solution(object):
    def convert(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return
        l_node, r_node = self.dfs(root)
        return l_node
    
    def dfs(self, node):
        if not node.left and not node.right: return (node, node)
        if node.left and node.right:
            l_bound = self.dfs(node.left)
            l_bound[1].right, node.left = node, l_bound[1]
            r_bound = self.dfs(node.right)
            r_bound[0].left, node.right = node, r_bound[0]
            return (l_bound[0], r_bound[1])
        
        if node.left:
            l_bound = self.dfs(node.left)
            l_bound[1].right, node.left = node, l_bound[1]
            return (l_bound[0], node)
            
        if node.right:
            r_bound = self.dfs(node.right)
            r_bound[0].left, node.right = node, r_bound[0]
            return (node, r_bound[1])