# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""
# dp method, time O(n^2)
def maxProductAfterCutting(length):
    """
    :type length: int
    :rtype: int
    """
    if length < 2: return 0
    if length == 2: return 1
    if length == 3: return 2
    res = [0] * (length + 1)
    res[1], res[2], res[3] = 1, 2, 3
    
    for i in range(4, length + 1):
        max_product = 0
        for j in range(1, length // 2 + 1):
            product = res[j] * res[i - j]
            max_product = max(max_product, product)
        res[i] = max_product
    return res[length]

# Greedy, time O(n), space O(1)
# when n >= 5, 3(n - 3) > 2(n - 2) > n
def maxProductAfterCutting1(length):
        """
        :type length: int
        :rtype: int
        """
        if length < 2: return 0
        if length == 2: return 1
        if length == 3: return 2
        if length == 4: return 4
        
        res = 1
        if length % 3 == 1: 
            res *= 4
            length -= 4
        elif length % 3 == 2:
            res *= 2
            length -= 2
        
        while length > 0:
            res *= 3
            length -= 3
        
        return res



if __name__ == "__main__":
    print(maxProductAfterCutting(58))
    print(maxProductAfterCutting1(58))

