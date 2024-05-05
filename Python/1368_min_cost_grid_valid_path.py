from typing import List
from collections import deque


class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        cost = [[99999 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        cost[0][0] = 0
        q = deque()
        q.append((0, 0))
        dr = [0, 0, 1, -1]
        dc = [1, -1, 0, 0]

        while len(q) > 0:
            c = q.popleft()

            if c[0] == len(grid) - 1 and c[1] == len(grid[0]) - 1:
                return cost[c[0]][c[1]]

            for i in range(4):
                n = c[0] + dr[i], c[1] + dc[i]
                if 0 <= n[0] < len(grid) and 0 <= n[1] < len(grid[0]):
                    w = 0 if grid[c[0]][c[1]] == i + 1 else 1
                    if cost[n[0]][n[1]] > cost[c[0]][c[1]] + w:
                        cost[n[0]][n[1]] = cost[c[0]][c[1]] + w
                        if w == 0:
                            q.appendleft(n)
                        else:
                            q.append(n)
        return cost[len(grid) - 1][len(grid[0]) - 1]


sol = Solution()

print(sol.minCost(grid=[[1, 1, 3], [3, 2, 2], [1, 1, 4]]))
