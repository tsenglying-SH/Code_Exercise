# -*- coding: utf-8 -*-
"""
Created on Sun Oct 20 14:10:45 2019

@author: 84685
"""

# classical DFS template
class Solution:
    def permutation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        
        nums.sort()
        path = []
        res = []
        visited = [False] * len(nums)
        
        self.dfs(nums, path, res, visited, 0)
        return res
        
    def dfs(self, nums, path, res, visited, idx):
        if idx == len(nums):
            res.append(path[:])
            return
        
        if idx > len(nums):
            return
        
        for i in range(len(nums)):
            if visited[i]: continue
            if i > 0 and nums[i] == nums[i - 1] and visited[i - 1]: continue
        
            visited[i] = True
            path.append(nums[i])
            self.dfs(nums, path, res, visited, idx + 1)
            path.pop()
            visited[i] = False
        