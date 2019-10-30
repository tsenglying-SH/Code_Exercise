# -*- coding: utf-8 -*-
"""
Created on Wed Oct 30 21:02:07 2019

@author: 84685
"""


class Solution(object):
    def leftRotateString(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: str
        """
        if n >= len(s): return s
        s = s[::-1]
        return s[len(s) - n - 1:: -1] + s[: len(s) - n - 1:-1]