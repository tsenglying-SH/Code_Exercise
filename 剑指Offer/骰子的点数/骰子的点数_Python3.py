# -*- coding: utf-8 -*-
"""
Created on Fri Nov  1 18:38:49 2019

@author: 84685
"""

# naive dp, time O(n^2), space O(n ^ 2)
class Solution(object):
    def numberOfDice(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n <= 0: return []
        dp = [[0] * (6 * n + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(i, 6 * i + 1):
                for k in range(1, 7):
                    if j - k >= 0:
                        dp[i][j] += dp[i - 1][j - k]
        return dp[n][n:]
    
    
# optimized version, time O(n ^ 2), space O(n)
class Solution(object):
    def numberOfDice(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n <= 0: return []
        dp = [0] * (6 * n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            # update in reverse order
            for j in range(6 * i, i - 1, -1):
                # remember initialization
                dp[j] = 0
                for k in range(1, 7):
                    if j - k >= i - 1:
                        dp[j] += dp[j - k]
        return dp[n:]