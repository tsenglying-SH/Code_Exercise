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

from collections import deque
class Solution:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root: return ""
        res = ""
        queue = deque([root])
        
        while queue:
            node = queue.popleft()
            
            if node:
                res += str(node.val) + ' '
                queue.append(node.left)
                queue.append(node.right)
            else:
                res += '# '
        i = len(res) - 1
        while i > 0 and res[i] == ' ': i -= 1
        return res[: i + 1]
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data: return
        data_list = data.split()
        
        i = 0
        head = TreeNode(int(data_list[i]))
        i += 1
        queue = deque([head])
        
        while queue:
            node = queue.popleft()
            
            if i < len(data_list) and data_list[i] != '#':
                print
                node.left = TreeNode(int(data_list[i]))
                queue.append(node.left)
            i += 1
            
            if i < len(data_list) and data_list[i] != '#':
                node.right = TreeNode(int(data_list[i]))
                queue.append(node.right)
            i += 1
        
        return head