# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 22:41:05 2019

@author: 84685
"""

# time O(32n), not the best method
class Solution(object):
    def findNumberAppearingOnce(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 3: return 0
        bit_cnt = [0] * 32
        for num in nums:
            for i in range(32):
                bit_cnt[i] += num >> i & 1
        
        res = 0
        for j in range(32):
            if bit_cnt[j] % 3 == 1:
                res += 1 << j
        return res

# the best method, tricky method, time O(n)
class Solution(object):
    def findNumberAppearingOnce(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 3: return 0
        one, two = 0, 0
        for num in nums:
            one = (num ^ one) & ~two
            two = (num ^ two) & ~one
        
        return one