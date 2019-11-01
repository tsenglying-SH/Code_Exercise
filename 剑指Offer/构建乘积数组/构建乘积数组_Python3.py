# -*- coding: utf-8 -*-
"""
Created on Fri Nov  1 22:59:42 2019

@author: 84685
"""

# 2 steps method, time O(n), space O(n)
class Solution(object):
    def multiply(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        if not A: return []
        res = [1] * len(A)
        for i in range(1, len(A)):
            res[i] = res[i - 1] * A[i - 1]
        
        factor = 1
        for i in range(len(A) - 2, -1, -1):
            factor *= A[i + 1]
            res[i] *= factor
        return res