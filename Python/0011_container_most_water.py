from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        start, end = 0, len(height) - 1
        max_area = (end - start) * min(height[end],height[start])
        while start < end:
            if height[start] < height[end]:
                start += 1
            elif height[end] < height[start]:
                end -= 1
            elif height[start + 1] > height[end - 1]:
                start += 1
            else:
                end -= 1
            max_area = max(max_area,(end - start) *  min(height[end],height[start]))
        return max_area

sol = Solution()
print(sol.maxArea([1,1]))

