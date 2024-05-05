import heapq
from typing import *


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        heap = [(-val, index) for index, val in enumerate(nums[0:k])]
        heapq.heapify(heap)
        window_maxes = []
        for index in range(k, len(nums) + 1):
            while heap[0][1] < index - k:
                heapq.heappop(heap)
            window_maxes.append(-heap[0][0])
            if index < len(nums):
                heapq.heappush(heap, (-nums[index], index))
        return window_maxes


sol = Solution()
print(sol.maxSlidingWindow(nums=[1, 3, -1, -3, 5, 3, 6, 7], k=3))
