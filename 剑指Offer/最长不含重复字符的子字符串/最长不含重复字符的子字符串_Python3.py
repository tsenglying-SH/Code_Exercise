# -*- coding: utf-8 -*-
"""
Created on Sat Oct 26 10:24:21 2019

@author: 84685
"""

# two pointers, time O(n)
class Solution:
    def longestSubstringWithoutDuplication(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return 0
        i, j, res = 0, 0, 1
        used = set()
        while j < len(s):
            if s[j] in used:
                while s[i] != s[j]:
                    used.remove(s[i])
                    i += 1
                i += 1
            else:
                used.add(s[j])
            res = max(res, j - i + 1)
            j += 1
        return res