# -*- coding: utf-8 -*-
"""
Created on Fri Oct 18 18:21:12 2019

@author: 84685
"""

# for loop is also ok, time O(m * n), space O(1)
class Solution(object):
    def printMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]: return []
        res = []
        m, n = len(matrix), len(matrix[0])
        row_max, row_min, col_max, col_min = m - 1, 0, n - 1, 0
        row, col = 0, 0
        count = m * n
        while count:
            while count and col <= col_max:
                res.append(matrix[row][col])
                count -= 1
                col += 1
            col -= 1
            row += 1
            while count and row <= row_max:
                res.append(matrix[row][col])
                count -= 1
                row += 1
            col -= 1
            row -= 1
            while count and col >= col_min:
                res.append(matrix[row][col])
                count -= 1
                col -= 1
            col += 1
            row -= 1
            while count and row > row_min:
                res.append(matrix[row][col])
                count -= 1
                row -= 1
            col += 1
            row += 1
            
            row_max -= 1
            row_min += 1
            col_max -= 1
            col_min += 1
        return res