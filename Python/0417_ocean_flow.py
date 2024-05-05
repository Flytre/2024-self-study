from typing import List


# DOES NOT WORK DUE TO RECURRING BETWEEN 2 TILES FOREVER

class Solution:
    FLAG_ATLANTIC = 2 * (10 ** 5)
    FLAG_PACIFIC = 4 * (10 ** 5)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        return list([[row, col]
                     for row in range(len(heights))
                     for col in range(len(heights[0]))
                     if self.can_flow(heights, row, col, heights[row][col], self.FLAG_PACIFIC)
                     and self.can_flow(heights, row, col, heights[row][col], self.FLAG_ATLANTIC)])

    def can_flow(self, heights: List[List[int]], row: int, col: int, from_val, flag: int):
        if row >= len(heights) or col >= len(heights[0]):
            return flag == self.FLAG_ATLANTIC
        if row < 0 or col < 0:
            return flag == self.FLAG_PACIFIC
        if (heights[row][col] % (flag * 2)) // flag == 1:
            return True
        if (heights[row][col] % self.FLAG_ATLANTIC) > (from_val % self.FLAG_ATLANTIC):
            return False

        heights[row][col] = heights[row][col] + flag \
            if (self.can_flow(heights, row + 1, col, heights[row][col], flag)
                or self.can_flow(heights, row - 1, col, heights[row][col], flag)
                or self.can_flow(heights, row, col + 1, heights[row][col], flag)
                or self.can_flow(heights, row, col - 1, heights[row][col], flag)) else 0

        return (heights[row][col] % (flag * 2)) // flag == 1


sol = Solution()
print(sol.pacificAtlantic([[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]))
