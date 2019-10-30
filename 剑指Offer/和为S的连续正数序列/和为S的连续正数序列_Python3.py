# -*- coding: utf-8 -*-
"""
Created on Wed Oct 30 19:33:14 2019

@author: 84685
"""

# 2 pointers, time O(n), space O(1)
class Solution(object):
    def findContinuousSequence(self, sum):
        """
        :type sum: int
        :rtype: List[List[int]]
        """
        if sum <= 0: return 0
        i, j, s = 1, 1, 1
        res = []
        while j <= sum // 2 + 1:
            if s < sum:
                j += 1
                s += j
            elif s > sum:
                s -= i
                i += 1
            else:
                res.append([i for i in range(i, j + 1)])
                j += 1
                s += j
        return res