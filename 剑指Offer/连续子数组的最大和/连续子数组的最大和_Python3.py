# -*- coding: utf-8 -*-
"""
Created on Wed Oct 23 20:06:59 2019

@author: 84685
"""

# time O(n)
import sys
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        val = -sys.maxsize - 1
        s = 0
        for num in nums:
            if s < 0: s = 0
            s += num
            val = max(val, s)
        
        return val