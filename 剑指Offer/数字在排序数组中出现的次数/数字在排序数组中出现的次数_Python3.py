# -*- coding: utf-8 -*-
"""
Created on Mon Oct 28 18:29:21 2019

@author: 84685
"""

# binary search, O(logn)
class Solution(object):
    def getNumberOfK(self, nums, k):
        """
        :type nums: list[int]
        :type k: int
        :rtype: int
        """
        if not nums: return 0
        up = self.upper_bound(nums, k)
        low = self.lower_bound(nums, k)
        return up - low
    
    def upper_bound(self, nums, k):
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] > k:
                r = mid - 1
            else:
                l = mid + 1
        
        return l
        
    def lower_bound(self, nums, k):
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] >= k:
                r = mid - 1
            else:
                l = mid + 1
        
        return l