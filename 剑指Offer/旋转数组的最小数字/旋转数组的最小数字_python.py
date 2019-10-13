# -*- coding: utf-8 -*-
"""
Created on Sat Oct 12 19:59:32 2019

@author: 84685
"""
# array may contains duplicate, so time O(n) or O(logn)
def findMin(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if not nums:
        return -1
    start, end = 0, len(nums) - 1
    
    while nums[start] == nums[end] and end > 0:
        end -= 1
        
    if nums[start] <= nums[end]:
        return nums[start]
        
    while start + 1 < end:
        mid = start + (end - start) // 2
        if nums[mid] >= nums[0]:
            start = mid
        else:
            end = mid
    return nums[end]