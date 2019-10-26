# -*- coding: utf-8 -*-
"""
Created on Sat Oct 26 16:52:34 2019

@author: 84685
"""

# hash map method, time O(n), space O(n)
class Solution:
    def firstNotRepeatingChar(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s: return '#'
        hash_map = {}
        for c in s:
            if c in hash_map: hash_map[c] += 1
            else: hash_map[c] = 1
        
        for c in s:
            if hash_map[c] == 1: return c
        return '#'