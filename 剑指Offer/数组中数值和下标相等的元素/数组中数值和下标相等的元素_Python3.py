# -*- coding: utf-8 -*-
"""
Created on Mon Oct 28 19:25:56 2019

@author: 84685
"""

# notice the corner case
class Solution(object):
    def getNumberSameAsIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return -1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] >= mid: r = mid - 1
            else: l = mid + 1
        # corner case, if the number doesn't exist
        return l if nums[l] == l else -1