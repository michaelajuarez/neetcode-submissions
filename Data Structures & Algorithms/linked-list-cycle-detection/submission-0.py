# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        check = set()
        cur = head

        while cur:
            if cur in check:
                return True
            check.add(cur)
            cur = cur.next

        return False