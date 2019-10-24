# -*- coding: utf-8 -*-
"""
Created on Thu Oct 24 19:27:21 2019

@author: 84685
"""

class Solution(object):
    def digitAtIndex(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 0: return -1
        if n == 0: return 0
        
        bit_num, bit_cnt, base = 1, 9, 1
        while n > bit_num * bit_cnt:
            n -= bit_num * bit_cnt
            bit_num += 1
            bit_cnt *= 10
            base *= 10
        
        order = (n - 1) // bit_num
        bit = (n - 1) % bit_num
        num = order + base
        return num // 10 ** (bit_num - 1 - bit) % 10