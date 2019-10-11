# -*- coding: utf-8 -*-
"""
Created on Fri Oct 11 22:46:45 2019

@author: 84685
"""
# Solution 1: time O(n), space O(n)
def replaceSpaces(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        i = 0
        res = ""
        while i < len(s):
            # print(s[i])
            if s[i] != " ":
                res += s[i]
                i += 1
            else:
                res += "%20"
                i += 1
        return res
    
# Solution 2: time O(n), space O(1)
# Python string is difficult to implement two pointers, I've implement it in Cpp