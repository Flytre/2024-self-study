from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_size = 0
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                if grid[row][col] == 1:
                    max_size = max(max_size, self.area_fill(grid, row, col))
        return max_size

    def area_fill(self, grid: List[List[int]], row: int, col: int) -> int:
        if row >= len(grid) or col >= len(grid[row]) or row < 0 or col < 0 or grid[row][col] != 1:
            return 0

        grid[row][col] = -1
        return 1 + self.area_fill(grid, row + 1, col) + self.area_fill(grid, row - 1, col) \
                 + self.area_fill(grid, row, col + 1) + self.area_fill(grid, row, col - 1)


sol = Solution()
print(sol.maxAreaOfIsland([[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                           [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
                           [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                           [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]))
