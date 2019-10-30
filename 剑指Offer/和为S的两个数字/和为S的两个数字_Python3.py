# -*- coding: utf-8 -*-
"""
Created on Wed Oct 30 18:18:20 2019

@author: 84685
"""

# application of hash table time O(m), space O(1)
class Solution(object):
    def findNumbersWithSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums: return [-1, -1]
        memo = {}
        for i in range(len(nums)):
            if target - nums[i] in memo:
                return [target - nums[i], nums[i]]
            else:
                memo[nums[i]] = i
        return [-1, -1]
    
# sort + 2 pointers, time O(nlogn), space O(1)
class Solution(object):
    def findNumbersWithSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums: return [-1, -1]
        nums.sort()
        i, j = 0, len(nums) - 1
        while i < j:
            if nums[i] + nums[j] < target: i += 1
            elif nums[i] + nums[j] > target: j -= 1
            else: return [nums[i], nums[j]]
        return [-1, -1]