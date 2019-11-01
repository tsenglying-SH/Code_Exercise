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
    
# we can change it into iterative method, time O(n), space O(1)
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n <= 0 or m <= 0: return 0
        if n == 1: return 0
        res = 0
        for i in range(2, n + 1):
            res = (res + m) % i
        return res    
        
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
    
# we can change it into iterative method, time O(n), space O(1)
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n <= 0 or m <= 0: return 0
        if n == 1: return 1
        res = 1
        for i in range(2, n + 1):
            res = (res + m - 1) % i + 1
        return res   