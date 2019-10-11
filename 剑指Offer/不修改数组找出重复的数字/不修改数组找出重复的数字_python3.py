# -*- coding: utf-8 -*-
"""
Created on Fri Oct 11 20:31:54 2019

@author: 84685
"""
# time O(nlogn), space is limited in O(1)
def duplicateInArray(nums):
    """
    :type nums: List[int]
    :rtype int
    """
    n = len(nums)
    start, end = 1, n
    while start <= end:
        mid = start + (end - start) // 2
        count = 0
        for num in nums:
            if num <= mid:
                count += 1
        if count > mid:
            end = mid - 1
        else:
            start = mid + 1
            
    return start

print(duplicateInArray([2, 3, 5, 4, 3, 2, 6, 7]))
print(duplicateInArray([6, 3, 1, 4, 5, 2, 6]))