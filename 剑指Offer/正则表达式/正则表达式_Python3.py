# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""

# normal DP method, time O(mn), space O(mn)

def isMatch(s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m, n = len(s), len(p)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True
        
        for j in range(1, n + 1):
            dp[0][j] = j >= 2 and p[j - 1] == '*' and p[j - 2] != '*' and dp[0][j - 2]
            
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if p[j - 1] != '*':
                    dp[i][j] = dp[i - 1][j - 1] and char_match(p[j - 1], s[i - 1])
                else:
                    dp[i][j] = j >= 2 and p[j - 2] != '*' and (dp[i][j - 2] or \
                    (dp[i - 1][j] and char_match(p[j - 2], s[i - 1])))
        
        return dp[-1][-1]
    
# memory search
def char_match(p_c, s_c):
    return p_c == '.' or p_c == s_c

print(isMatch('aaa', 'a*'))

def isMatch1(s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        return helper1(s, p, 0, 0, {})
    
def helper1(s, p, i, j, memo):
    if (i, j) in memo:
        return memo[(i, j)]
    
    m, n = len(s), len(p)
    if i >= m:
        if (n - j) & 1:
            return False
        
        for idx in range(j, n, 2):
            if p[idx + 1] != '*':
                return False
        return True
        
    if j >= n:
        return i >= m
        
    if j + 1 <= n - 1 and p[j + 1] == '*':
        res = helper1(s, p, i, j + 2, memo) or (helper1(s, p, i + 1, j,memo) and char_match1(p[j], s[i]))
    else:
        res = helper1(s, p, i + 1, j + 1, memo) and char_match1(p[j], s[i])
             
    if res not in memo:
        memo[(i, j)] = res
    return res
       
def char_match1(p_c, s_c):
    return p_c == '.' or p_c == s_c

print(isMatch1('aaa', 'a*'))