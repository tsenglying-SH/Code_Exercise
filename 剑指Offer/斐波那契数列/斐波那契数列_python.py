# -*- coding: utf-8 -*-
"""
Created on Sat Oct 12 19:59:32 2019

@author: 84685
"""
# normal way, like dp method, Time O(n)， space O(1)
def Fibonacci(n):
    """
    :type n: int
    :rtype: int
    """
    if n <= 0:
        return 0

    pre_cur = [0, 1]
    for _ in range(n):
        tmp = pre_cur[0]
        pre_cur[0] = pre_cur[1]
        pre_cur[1] = tmp + pre_cur[0]

    return pre_cur[0]


# use the format, time O(logn)
def Fibonacci1(n):
    """
    :type n: int
    :rtype: int
    """
    if n <= 0:
        return 0

    sqrt5 = pow(5, 0.5)
    res = 1.0 / sqrt5 * (pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n))
    return int(res)

# tricky way, matrix pow, time O(logn)
def Fibonacci2(n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 0:
            return 0

        ans = fast_pow([[1, 1], [1, 0]], n + 1)
        return ans[1][1]
    
def matrix_product(m_a, m_b):
    if not m_a or not m_a[0] or not m_b or not m_b[0] or len(m_a[0]) != len(m_b):
        return
    m, n, p = len(m_a), len(m_a[0]), len(m_b[0])

    res = [[0] * p for _ in range(m)]
    for i in range(m):
        for j in range(p):
            for k in range(n):
                res[i][j] += m_a[i][k] * m_b[k][j]
    return res

def fast_pow(mat, n):
    if n == 0:
        return [[1, 0], [0, 1]]

    if n == 1:
        return mat

    ans = [[1, 0], [0, 1]]
    while n > 0:
        if n & 1:
            ans = matrix_product(ans, mat)
        mat = matrix_product(mat, mat)
        n >>= 1
    return ans