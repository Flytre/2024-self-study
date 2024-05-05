from collections import deque
from typing import *


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        decreasing = deque()
        for i in range(0, k):
            while decreasing and nums[i] > nums[decreasing[-1]]:
                decreasing.pop()
            decreasing.append(i)
        for i in range(k, len(nums)+1):
            if decreasing[0] < i - k:
                decreasing.popleft()
            res.append(nums[decreasing[0]])

            if i < len(nums):
                while decreasing and nums[i] > nums[decreasing[-1]]:
                    decreasing.pop()
                decreasing.append(i)
        return res


sol = Solution()
print(sol.maxSlidingWindow(nums=[1, -1], k=1))
