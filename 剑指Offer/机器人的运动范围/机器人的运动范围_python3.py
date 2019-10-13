# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""
# Recursive DFS, time O(rows * cols)
class Solution(object):
    def movingCount(self, threshold, rows, cols):
        """
        :type threshold: int
        :type rows: int
        :type cols: int
        :rtype: int
        """
        if rows <= 0 or cols <= 0 or threshold < 0:
            return 0
        
        self.count = 0
        visited = set()
        self.dfs(0, 0, threshold, rows, cols, visited)
        return self.count
    
    def dfs(self, x, y, threshold, rows, cols, visited):
        if (x, y) not in visited:
            visited.add((x, y))
            self.count += 1
        
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            new_x = x + dx
            new_y = y + dy
            if 0 <= new_x < rows and 0 <= new_y < cols and (new_x, new_y) not in visited \
            and self.cal_sum(new_x, new_y) <= threshold:
                self.dfs(new_x, new_y, threshold, rows, cols, visited)
            
    def cal_sum(self, x, y):
        res = 0
        while x > 0:
            res += x % 10
            x //= 10
        while y > 0:
            res += y % 10
            y //= 10
        return res
    
# BFS, time O(rows * cols)
from collections import deque
class Solution(object):
    def movingCount(self, threshold, rows, cols):
        """
        :type threshold: int
        :type rows: int
        :type cols: int
        :rtype: int
        """
        if rows <= 0 or cols <= 0 or threshold < 0:
            return 0
        
        self.count = 1
        visited = {(0, 0)}
        queue = deque([(0, 0)])
        
        while queue:
            x, y = queue.popleft()
            for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                new_x = x + dx
                new_y = y + dy
                if 0 <= new_x < rows and 0 <= new_y < cols and self.cal_sum(new_x, new_y) <= threshold\
                and (new_x, new_y) not in visited:
                    queue.append((new_x, new_y))
                    visited.add((new_x, new_y))
                    self.count += 1
        return self.count
        
    def cal_sum(self, x, y):
        res = 0
        while x > 0:
            res += x % 10
            x //= 10
        while y > 0:
            res += y % 10
            y //= 10
        return res
    
    
# change the queue of the BFS to stack, then it's iterative DFS, time O(rows * cols)
from collections import deque
class Solution(object):
    def movingCount(self, threshold, rows, cols):
        """
        :type threshold: int
        :type rows: int
        :type cols: int
        :rtype: int
        """
        if rows <= 0 or cols <= 0 or threshold < 0:
            return 0
        
        self.count = 1
        visited = {(0, 0)}
        stack = deque([(0, 0)])
        
        while stack:
            x, y = stack.pop()
            for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                new_x = x + dx
                new_y = y + dy
                if 0 <= new_x < rows and 0 <= new_y < cols and self.cal_sum(new_x, new_y) <= threshold\
                and (new_x, new_y) not in visited:
                    stack.append((new_x, new_y))
                    visited.add((new_x, new_y))
                    self.count += 1
        return self.count
        
    def cal_sum(self, x, y):
        res = 0
        while x > 0:
            res += x % 10
            x //= 10
        while y > 0:
            res += y % 10
            y //= 10
        return res