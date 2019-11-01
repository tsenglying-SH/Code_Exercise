# -*- coding: utf-8 -*-
"""
Created on Fri Nov  1 21:03:55 2019

@author: 84685
"""

# zero-base, time O(n), space O(n)
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n <= 0 or m <= 0: return 0
        if n == 1: return 0
        return (self.lastRemaining(n - 1, m) + m) % n
    
# one-base, time O(n), space O(n)
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n <= 0 or m <= 0: return 0
        if n == 1: return 1
        return (self.lastRemaining(n - 1, m) + m - 1) % n + 1