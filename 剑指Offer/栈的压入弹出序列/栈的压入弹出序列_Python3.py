# -*- coding: utf-8 -*-
"""
Created on Sat Oct 19 16:31:26 2019

@author: 84685
"""

# time O(n)
class Solution(object):
    def isPopOrder(self, pushV, popV):
        """
        :type pushV: list[int]
        :type popV: list[int]
        :rtype: bool
        """
        # corner case
        if not pushV and not popV: return True
        if len(pushV) != len(popV): return False
        
        stk = []
        push_idx, pop_idx = 0, 0
        # if some elements hasn't been popped, do the loop
        while pop_idx < len(popV):
            # if the elements to be pop not on the top of the stack, 
            # push somthing in
            if not stk or stk[-1] != popV[pop_idx]:
                # all elements has been pushed in but top is not the elements 
                # to be popped, return false
                if push_idx >= len(pushV): return False
                stk.append(pushV[push_idx])
                push_idx += 1
            else:
                # element to be popped do on the top
                stk.pop()
                pop_idx += 1
                
        return True