# -*- coding: utf-8 -*-
"""
Created on Mon Oct 21 19:04:34 2019

@author: 84685
"""

# method 1, partition method, time O(n), the number must be the median in nums
class Solution(object):
    def moreThanHalfNum_Solution(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return -1
        return self.partition(nums, 0, len(nums) - 1, (len(nums) + 1) // 2)
    
    def partition(self, nums, start, end, k):
        if start > end: return -1
        if start == end and k == 1:
            return nums[start]
        
        l, r = start, end
        mid = start + (end - start) // 2
        pivot = nums[mid]
        
        while l <= r:
            while l <= r and nums[l] < pivot: l += 1
            while l <= r and nums[r] > pivot: r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        
        if start + k - 1 <= r:
            return self.partition(nums, start, r, k)
        elif start + k - 1 >= l:
            return self.partition(nums, l, end, k - l + start)
        else:
            return pivot
        
        
# method 2, really tricky method, time O(n)
class Solution(object):
    def moreThanHalfNum_Solution(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return -1
        
        val, cnt = nums[0], 1
        for i in range(1, len(nums)):
            if cnt == 0:
                val = nums[i]
                cnt = 1
            elif nums[i] == val:
                cnt += 1
            else:
                cnt -= 1
        return val