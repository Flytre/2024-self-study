from typing import *


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        p1, p2, mx = 0, len(heights) - 1, 0
        while p1 <= p2:
            mx = max(mx, min(heights[p1], heights[p2]) * (p2 - p1 + 1))
            if heights[p1] < heights[p2]:
                p1 += 1
            else:
                p2 -= 1
        return mx


sol = Solution()
print(sol.largestRectangleArea([2,1,5,6,2,3]))
