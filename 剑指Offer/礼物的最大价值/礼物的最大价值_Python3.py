# -*- coding: utf-8 -*-
"""
Created on Fri Oct 25 23:18:50 2019

@author: 84685
"""

# dp method, time O(m * n), space O(m * n)
class Solution(object):
    def getMaxValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]: return 0
        m, n = len(grid), len(grid[0])
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
    
# dp method with optimized space, time O(m * n), space O(n)
class Solution(object):
    def getMaxValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]: return 0
        m, n = len(grid), len(grid[0])
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[j] = grid[i - 1][j - 1] + max(dp[j], dp[j - 1])
        return dp[-1]
        