from typing import List
import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        inverted = [-num for num in nums]
        heapq.heapify(inverted)
        for i in range(0, k - 1):
            heapq.heappop(inverted)
        return -heapq.heappop(inverted)


sol = Solution()
print(sol.findKthLargest([3, 2, 1, 5, 6, 4], 2))
