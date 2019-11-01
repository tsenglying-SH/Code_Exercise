# -*- coding: utf-8 -*-
"""
Created on Fri Nov  1 20:35:57 2019

@author: 84685
"""

# time O(nlogn) due to sort
class Solution(object):
    def isContinuous(self, numbers):
        """
        :type numbers: List[int]
        :rtype: bool
        """
        # check whether there is five cards
        if len(numbers) != 5: return False
        numbers.sort()
        # check there are at most 4 kings
        i = 0
        while i < 5 and numbers[i] == 0: i += 1
        if i >= 4: return False
        # check the cards are within the valid range
        if numbers[-1] - numbers[i] > 4: return False
        # check there are no duplicates in cards
        for idx in range(i + 1, 5):
            if numbers[idx] == numbers[idx - 1]:
                return False
        return True