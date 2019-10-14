# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""
# fast power, O(logn), and pay attention to corner case
class Solution(object):
    def Power(self, base, exponent):
        """
        :type base: float
        :type exponent: int
        :rtype: float
        """
        self.input_is_valid = True
        # pow(0, negative number), not ok
        if abs(base) < 0.0001 and exponent < 0:
            self.input_is_valid = False
            return 0
        # pow(0, 0), we set it to 0
        if abs(base) < 0.0001 and exponent == 0:
            return 0
        # unnecessary to calculate
        if exponent == 1:
            return base
            
        if exponent < 0:
            exponent = -exponent
            base = 1.0 / base
        
        res = 1
        while exponent > 0:
            if exponent & 1:
                res *= base
            base *= base
            exponent >>= 1
        return res

