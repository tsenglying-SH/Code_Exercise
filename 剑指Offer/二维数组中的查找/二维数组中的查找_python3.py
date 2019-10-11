# -*- coding: utf-8 -*-
"""
Created on Fri Oct 11 22:06:57 2019

@author: 84685
"""
# time O(row + col), no extra space
def searchArray(array, target):
    """
    :type array: List[List[int]]
    :type target: int
    :rtype: bool
    """
    if not array or not array[0]:
        return False
    row, col = 0, len(array) - 1
    while row <= len(array) - 1 and col >= 0:
        if array[row][col] == target:
            return True
        elif array[row][col] > target:
            col -= 1
        else:
            row += 1
    
    return False

print(searchArray([[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]], 7))