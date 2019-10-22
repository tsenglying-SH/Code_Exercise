# -*- coding: utf-8 -*-
"""
Created on Tue Oct 22 18:11:21 2019

@author: 84685
"""

# partition method, time O(n + klogk), space O(1)
class Solution(object):
    def getLeastNumbers_Solution(self, input, k):
        """
        :type input: list[int]
        :type k: int
        :rtype: list[int]
        """
        if not input or k > len(input) or k <= 0: return []
        res = []
        self.partition(input, 0, len(input) - 1, k, res)
        res.sort()
        return res
    
    def partition(self, nums, start, end, k, res):
        if start > end: return
        if start == end and k == 1:
            res.append(nums[start])
            return
        
        l, r = start, end
        mid = l + (r - l) // 2
        pivot = nums[mid]
        
        while l <= r:
            while l <= r and nums[l] < pivot:
                l += 1
            while l <= r and nums[r] > pivot:
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        
        if start + k - 1 <= r:
            self.partition(nums, start, r, k, res)
        elif start + k - 1 >= l:
            res.extend(nums[start: l])
            self.partition(nums, l, end, k - l + start, res)
        else:
            res.extend(nums[start: l])
            
# heap based method, time O(nlogk), space O(k)
import heapq
class Solution(object):
    def getLeastNumbers_Solution(self, input, k):
        """
        :type input: list[int]
        :type k: int
        :rtype: list[int]
        """
        if not input or k <= 0 or k > len(input): return []
        heap = []
        for e in input:
            heapq.heappush(heap, -e)
            
            if len(heap) > k:
                heapq.heappop(heap)
        
        res = []
        for _ in range(k):
            res.append(-heapq.heappop(heap))
        
        return res[::-1]