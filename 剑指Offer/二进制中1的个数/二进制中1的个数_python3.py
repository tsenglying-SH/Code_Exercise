# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""
# substract the last 1, time O(logn)

def NumberOf1(n):
    """
    :type n: int
    :rtype: int
    """
    count = 0
    while n & 0xFFFFFFFF != 0:
        count += 1
        n -= n & -n
    return count
print(NumberOf1(9))
print(NumberOf1(-1))

