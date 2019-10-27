# -*- coding: utf-8 -*-
"""
Created on Sun Oct 27 13:53:23 2019

@author: 84685
"""

# piggy back on merge sort, time O(nlogn), space O(n)
class Solution(object):
    def __init__(self):
        self.count = 0
        
    def inversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return self.count
        self.merge_sort(nums, 0, len(nums) - 1)
        return self.count
        
    def merge_sort(self, nums, start, end):
        if start >= end: return
        mid = start + (end - start) // 2
        self.merge_sort(nums, start, mid)
        self.merge_sort(nums, mid + 1, end)
        self.merge(nums, start, mid, end)
        
    def merge(self, nums, start, mid, end):
        helper = [0] * len(nums)
        i, j, k = start, mid + 1, start
        while i <= mid and j <= end:
            if nums[i] <= nums[j]:
                helper[k] = nums[i]
                k += 1
                i += 1
            else:
                self.count += mid - i + 1
                helper[k] = nums[j]
                k += 1
                j += 1
            
        while i <= mid:
            helper[k] = nums[i]
            k += 1
            i += 1
        while j <= end:
            helper[k] = nums[j]
            k += 1
            j += 1
        
        for idx in range(start, end + 1):
            nums[idx] = helper[idx]