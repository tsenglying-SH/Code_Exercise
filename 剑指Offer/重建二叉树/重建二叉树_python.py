# -*- coding: utf-8 -*-
"""
Created on Sat Oct 12 19:59:32 2019

@author: 84685
"""

# Acwing Solution via Recursion, time O(n^2), space O(h)

# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder or not inorder or len(preorder) != len(inorder):
            return
        return self.helper(preorder, inorder, 0, len(preorder) - 1, 0, len(inorder) - 1)
        
    def helper(self, preorder, inorder, p_start, p_end, i_start, i_end):
        if p_start > p_end or i_start > i_end:
            return
        node = TreeNode(preorder[p_start])
        if p_start == p_end and i_start == i_end:
            return node
        i_center = -1
        # here, some optimization can be done via save the position in a map to avoid too much linear search
        for i in range(i_start, i_end + 1):
            if inorder[i] == preorder[p_start]:
                i_center = i
        
        node.left = self.helper(preorder, inorder, p_start + 1, p_start + i_center - i_start, i_start, i_center - 1)
        node.right = self.helper(preorder, inorder, p_start + i_center - i_start + 1, p_end, i_center + 1, i_end)
        return node
    
    
# optimized version, time O(n), space O(h + n)
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder or not inorder or len(preorder) != len(inorder):
            return
        self.e_p = {}
        for i in range(len(inorder)):
            self.e_p[inorder[i]] = i
        
        return self.helper(preorder, inorder, 0, len(preorder) - 1, 0, len(inorder) - 1)
        
    def helper(self, preorder, inorder, p_start, p_end, i_start, i_end):
        if p_start > p_end or i_start > i_end:
            return
        node = TreeNode(preorder[p_start])
        if p_start == p_end and i_start == i_end:
            return node
        i_center = self.e_p[preorder[p_start]]
        
        node.left = self.helper(preorder, inorder, p_start + 1, p_start + i_center - i_start, i_start, i_center - 1)
        node.right = self.helper(preorder, inorder, p_start + i_center - i_start + 1, p_end, i_center + 1, i_end)
        return node
        