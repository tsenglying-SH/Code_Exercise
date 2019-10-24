# -*- coding: utf-8 -*-
"""
Created on Thu Oct 24 21:30:34 2019

@author: 84685
"""

class Solution(object):
    def printMinNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not nums:
            return ""
        
        self.partition(nums, 0, len(nums) - 1)
        res = ""
        for num in nums:
            res += str(num)
        return res
        
    def partition(self, nums, start, end):
        if start >= end: return
        l, r = start, end
        mid = start + (end - start) // 2
        pivot = nums[mid]
        while l <= r:
            while l <= r and self.cmp(nums[l], pivot):
                l += 1
            while l <= r and self.cmp(pivot, nums[r]):
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        self.partition(nums, start, r)
        self.partition(nums, l, end)
    

    def cmp(self, a, b):
        return str(a) + str(b) < str(b) + str(a)