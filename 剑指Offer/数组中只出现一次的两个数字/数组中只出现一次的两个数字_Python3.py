# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 21:16:20 2019

@author: 84685
"""

# application of exclusive OR, time O(n)
class Solution(object):
    def findNumsAppearOnce(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) < 2: return []
        sum = 0
        for num in nums:
            sum ^= num
        lowbit = sum & -sum
        
        num1, num2 = 0, 0
        for num in nums:
            if lowbit & num:
                num1 ^= num
            else:
                num2 ^= num
        return [num1, num2]