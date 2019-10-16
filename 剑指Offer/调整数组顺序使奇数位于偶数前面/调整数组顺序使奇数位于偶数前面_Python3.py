# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""

# two pointer in the same direction, time O(n)
def reOrderArray(array):
    """
    :type array: List[int]
    :rtype: void
    """
    if not array:
        return
    
    i, j = 0, 0
    while j < len(array):
        if array[j] & 1:
            array[i], array[j] = array[j], array[i]
            i += 1
            j += 1
        else:
            j += 1

a = [1, 2, 3, 4, 5]
print(reOrderArray(a))
print(a)

# reusable version 1
def reOrderArray(array):
        """
        :type array: List[int]
        :rtype: void
        """
        helper(array, x3)
    
def helper(array, func):
    if not array:
        return
    
    i, j = 0, 0
    while j < len(array):
        if func(array[j]):
            array[i], array[j] = array[j], array[i]
            i += 1
            j += 1
        else:
            j += 1
def isOdd(x):
    return x & 1
def x3(x):
    return x % 3 == 0

a = [1, 2, 3, 4, 5]
print(reOrderArray(a))
print(a)




# two pointer in different direction, just like partition template in quick 
# sort!, time O(n)

def reOrderArray1(array):
    """
    :type array: List[int]
    :rtype: void
    """
    if not array:
        return
    i, j = 0, len(array) - 1
    while i <= j:
        while i <= j and (array[i] & 1):
            i += 1
        while i <= j and not (array[j] & 1):
            j -= 1
        if i <= j:
            array[i], array[j] = array[j], array[i]
            i += 1
            j -= 1
a = [1, 2, 3, 4, 5]
print(reOrderArray1(a))
print(a)

# reusable version 2
def reOrderArray(array):
        """
        :type array: List[int]
        :rtype: void
        """
        helper(array, x3)
    
def helper(array, func):
    if not array:
        return
    i, j = 0, len(array) - 1
    while i <= j:
        while i <= j and func(array[i]):
            i += 1
        while i <= j and not func(array[j]):
            j -= 1
        if i <= j:
            array[i], array[j] = array[j], array[i]
            i += 1
            j -= 1
def isOdd(x):
    return x & 1
def x3(x):
    return x % 3 == 0
a = [1, 2, 3, 4, 5]
print(reOrderArray(a))
print(a)