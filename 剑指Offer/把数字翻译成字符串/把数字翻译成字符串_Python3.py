# -*- coding: utf-8 -*-
"""
Created on Fri Oct 25 23:07:51 2019

@author: 84685
"""

# only 0-25 can be translated to character, dp method, time O(n)
class Solution:
    def getTranslationCount(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return -1
        dp = (len(s) + 1)* [0]
        dp[0] = 1
        for i in range(1, len(s) + 1):
            dp[i] = dp[i - 1]
            if i > 1:
                two_bit = int(s[i - 2: i])
                if 10 <= two_bit <= 25: dp[i] += dp[i - 2]
        return dp[-1]