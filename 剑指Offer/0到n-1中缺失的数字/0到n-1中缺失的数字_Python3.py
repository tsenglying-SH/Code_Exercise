# -*- coding: utf-8 -*-
"""
Created on Mon Oct 28 19:12:38 2019

@author: 84685
"""

# binary search, time O(logn)
class Solution(object):
    def getMissingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == mid: l = mid + 1
            else: r = mid - 1
        return l