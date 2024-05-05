# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self.val) + ", " + str(self.next)


from typing import List, Optional
import heapq


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap, remaining = [], len(lists)
        for index, ls in enumerate(lists):
            if ls is None:
                remaining -= 1
            else:
                heap.append((ls.val, index))
        heapq.heapify(heap)  # min heap in Python
        head, curr = None, None
        while remaining > 0:
            val, index = heapq.heappop(heap)
            if head is None:
                curr = head = lists[index]
            else:
                curr.next = lists[index]
                curr = curr.next
            lists[index] = lists[index].next
            if lists[index] is None:
                remaining -= 1
            else:
                heapq.heappush(heap, (lists[index].val, index))
        return head


sol = Solution()
out = sol.mergeKLists([None, ListNode(1, ListNode(4, ListNode(5))),
                       ListNode(1, ListNode(3, ListNode(4))),
                       ListNode(2, ListNode(6))])
print(out)
