# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 15:28:14 2019

@author: 84685
"""

# to get whether the node is in the list, it have to take O(n), 
# so here assume that the node to be deleted is really in the List.
class Node():
    def __init__(self, val):
        self.val = val
        self.next = None
        
def DeleteNode(pointertoHead, NodeToDelete):
    # corner case: invalid input
    if not pointertoHead.next or not NodeToDelete:
        return
    
    # if the node to delete is not the tail
    if NodeToDelete.next:
        pNext = NodeToDelete.next
        NodeToDelete.val = pNext.val
        NodeToDelete.next = pNext.next
        del pNext
    
    
    elif pointertoHead.next == NodeToDelete:
        del NodeToDelete
        pointertoHead.next = None
        
    else:
        pPre = pointertoHead.next
        while pPre.next != NodeToDelete:
            pPre = pPre.next
        
        pPre.next = None
        del NodeToDelete