# -*- coding: utf-8 -*-
"""
Created on Sat Oct 12 19:59:32 2019

@author: 84685
"""
# pop O(1), peek O(1), empty O(1), push O(n)
class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.s1 = []
        self.s2 = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        while self.s2:
            self.s1.append(self.s2.pop())
        self.s1.append(x)
        while self.s1:
            self.s2.append(self.s1.pop())
        

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        return self.s2.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        return self.s2[-1]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return len(self.s2) == 0
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()