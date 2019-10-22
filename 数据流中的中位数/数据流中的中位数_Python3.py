# -*- coding: utf-8 -*-
"""
Created on Tue Oct 22 19:53:09 2019

@author: 84685
"""

# heap based method, time O(logn), Python's heap is so messy.
import heapq
class Solution:
    def __init__(self):
        self.minHeap = []
        self.maxHeap = []
    
    def insert(self, num):
        """
        :type num: int
        :rtype: void
        """
        if not self.maxHeap or num <= -self.maxHeap[0]:
            heapq.heappush(self.maxHeap, -num)
        else:
            heapq.heappush(self.minHeap, num)
        
        while len(self.maxHeap) < len(self.minHeap):
            heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))
        
        while len(self.maxHeap) > len(self.minHeap) + 1:
            heapq.heappush(self.minHeap, -heapq.heappop(self.maxHeap))
        
        
    def getMedian(self):
        """
        :rtype: float
        """
        total_size = len(self.minHeap) + len(self.maxHeap)
        if total_size & 1:
            return -self.maxHeap[0]
        return self.minHeap[0] / 2.0 - self.maxHeap[0] / 2.0