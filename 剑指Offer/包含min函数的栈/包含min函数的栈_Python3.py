# -*- coding: utf-8 -*-
"""
Created on Fri Oct 18 18:21:12 2019

@author: 84685
"""

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s1 = []
        self.s2 = []

    def push(self, x: int) -> None:
        self.s1.append(x)
        if not self.s2 or x <= self.s2[-1]:
            self.s2.append(x)
        

    def pop(self) -> None:
        if self.s1[-1] == self.s2[-1]:
            self.s2.pop()
        self.s1.pop()

    def top(self) -> int:
        return self.s1[-1]

    def getMin(self) -> int:
        return self.s2[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()