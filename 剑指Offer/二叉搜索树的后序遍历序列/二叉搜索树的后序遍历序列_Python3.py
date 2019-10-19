# -*- coding: utf-8 -*-
"""
Created on Sat Oct 19 20:00:17 2019

@author: 84685
"""

class Solution:
    def verifySequenceOfBST(self, sequence):
        """
        :type sequence: List[int]
        :rtype: bool
        """
        if not sequence: return True
        return self.isValid(sequence, 0, len(sequence) - 1)
        
    def isValid(self, seq, l, r):
        if l >= r: return True
        k = l
        while k < r and seq[k] < seq[r]:
            k += 1
        for i in range(k, r):
            if seq[i] < seq[r]:
                return False
        return self.isValid(seq, l, k - 1) and self.isValid(seq, k, r - 1)