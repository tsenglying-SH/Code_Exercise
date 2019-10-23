# -*- coding: utf-8 -*-
"""
Created on Wed Oct 23 21:54:24 2019

@author: 84685
"""
# count bit by bit, time O(logn)
class Solution(object):
    def numberOf1Between1AndN_Solution(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 1: return 0
        count = 0
        factor = 1
        while n // factor:
            left = n // (10 * factor)
            cur_bit = (n // factor) % 10
            right = n % factor
            
            if cur_bit == 0:
                count += left * factor
            elif cur_bit == 1:
                count += left * factor + right + 1
            else:
                count += (left + 1) * factor
            factor *= 10
        return count