# -*- coding: utf-8 -*-
"""
Created on Sat Oct 26 10:27:31 2019

@author: 84685
"""

# dp method, time O(n), space O(n)
class Solution(object):
    def getUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0: return 0
        i, j, k = 0, 0, 0
        dp = [0] * n
        dp[0] = 1
        for idx in range(1, n):
            candidate = min(dp[i] * 2, dp[j] * 3, dp[k] * 5)
            dp[idx] = candidate
            if candidate == dp[i] * 2: i += 1
            if candidate == dp[j] * 3: j += 1
            if candidate == dp[k] * 5: k += 1
        return dp[-1]