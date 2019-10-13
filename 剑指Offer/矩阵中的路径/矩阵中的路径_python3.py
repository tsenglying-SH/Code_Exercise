# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""
# Acwing DFS
class Solution(object):
    def hasPath(self, matrix, string):
        """
        :type matrix: List[List[str]]
        :type string: str
        :rtype: bool
        """
        if not matrix or not matrix[0] or not string:
            return False
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if (self.dfs(matrix, string, 0, i, j)):
                    return True
        
        return False
        
    def dfs(self, matrix, string, idx, x, y):
        if matrix[x][y] != string[idx]:
            return False
        if idx == len(string) - 1:
            return True
            
        tmp = matrix[x][y]
        matrix[x][y] = '#'
        
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            new_x = x + dx
            new_y = y + dy
            if new_x >= 0 and new_x < len(matrix) and new_y >= 0 and new_y < len(matrix[0]):
                if self.dfs(matrix, string, idx + 1, new_x, new_y):
                    return True

        matrix[x][y] = tmp
        return False