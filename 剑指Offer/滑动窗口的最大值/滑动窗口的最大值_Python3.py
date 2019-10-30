# -*- coding: utf-8 -*-
"""
Created on Wed Oct 30 22:45:47 2019

@author: 84685
"""

# deque method, time O(n), space O(k)
from collections import deque
class Solution(object):
    def maxInWindows(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums or k <= 0 or len(nums) < k: return []
        res = []
        win_of_idx = deque([])
        for i in range(len(nums)):
            while win_of_idx and win_of_idx[0] + k - 1 < i:
                win_of_idx.popleft()
            while win_of_idx and nums[win_of_idx[-1]] <= nums[i]:
                win_of_idx.pop()
            win_of_idx.append(i)
            if i >= k - 1: res.append(nums[win_of_idx[0]])
        return res