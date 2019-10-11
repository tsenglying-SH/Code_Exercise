# -*- coding: utf-8 -*-
"""
Created on Fri Oct 11 19:24:18 2019

@author: 84685
"""
# Acwing, time O(n), space O(1)
def duplicateInArray(nums):
        """
        :type nums: List[int]
        :rtype int
        """
        if not nums:
            return -1
        
        n = len(nums)
        for num in nums:
            if num < 0 or num >= n:
                return -1
        
        for i in range(n):
            while nums[i] != i:
                if nums[i] != nums[nums[i]]:
                    tmp = nums[nums[i]]
                    nums[nums[i]] = nums[i]
                    nums[i] = tmp
                    # nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
                else:
                    return nums[i]
                
        return -1
    
print(duplicateInArray([2, 3, 5, 4, 3, 2, 6, 7]))

# Newcode, time O(n), space O(1)
def duplicate(nums, duplication):
    # write code here
    if not nums:
        return False
    
    n = len(nums)
    for num in nums:
        if num < 0 or num >= n:
            return False
    
    for i in range(n):
        while nums[i] != i:
            if nums[i] != nums[nums[i]]:
                # tmp = nums[nums[i]]
                # nums[nums[i]] = nums[i]
                # nums[i] = tmp
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
            else:
                duplication[0] = nums[i]
                return True
            
    return False
print(duplicate([2, 3, 5, 4, 3, 2, 6, 7], [1]))
