from typing import *
from collections import deque


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        max_elt = max(range(0, len(nums)), key=lambda i: nums[i])
        res = [-1] * len(nums)
        stack = deque()
        for d in reversed(range(len(nums))):
            index = (d + max_elt + 1) % len(nums)
            while stack and stack[-1] <= nums[index]:
                stack.pop()
            if stack:
                res[index] = stack[-1]
            if not stack or nums[index] < stack[-1]:
                stack.append(nums[index])
        return res


sol = Solution()
print(sol.nextGreaterElements(nums=[1, 2, 3, 4, 3]))
