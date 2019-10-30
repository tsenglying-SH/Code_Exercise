# -*- coding: utf-8 -*-
"""
Created on Wed Oct 30 20:04:25 2019

@author: 84685
"""

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s: return ""
        s = s[::-1].split()
        for i in range(len(s)):
            s[i] = s[i][::-1]
        return ' '.join(s)