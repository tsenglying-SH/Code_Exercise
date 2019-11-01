# -*- coding: utf-8 -*-
"""
Created on Fri Nov  1 21:24:38 2019

@author: 84685
"""

# time O(n)
class Solution(object):
    def maxDiff(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        res = 0
        cur_min = nums[0]
        for i in range(len(nums)):
            cur_min = min(nums[i], cur_min)
            res = max(res, nums[i] - cur_min)
        return res