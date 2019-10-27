# -*- coding: utf-8 -*-
"""
Created on Sun Oct 27 12:22:46 2019

@author: 84685
"""

# time totally O(n), on average O(1)
# space O(n), if char only a-z, it's O(1), exacylt O(26)
from collections import deque
class Solution:  
    def __init__(self):
        self.queue = deque([])
        self.counter = {}
    
    def firstAppearingOnce(self):
        """
        :rtype: str
        """
        return self.queue[0] if self.queue else '#'
        
    def insert(self, char):
        """
        :type char: str
        :rtype: void
        """
        if char not in self.counter:
            self.counter[char] = 1
            self.queue.append(char)
        else:
            self.counter[char] += 1
            while self.queue and self.counter[self.queue[0]] > 1:
                self.queue.popleft()
            