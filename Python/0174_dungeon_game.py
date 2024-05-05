from typing import List, Tuple


class Solution:

    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        return self.calc(dungeon, [[None for _ in range(len(dungeon[0]))] for _ in range(len(dungeon))])

    def calc(self, dungeon, dp, r=0, c=0):
        n = len(dungeon)
        m = len(dungeon[0])
        if r == n or c == m:
            return 1e9

        if r == n - 1 and c == m - 1:
            return -dungeon[r][c] + 1 if dungeon[r][c] <= 0 else 1

        if dp[r][c] is not None:
            return dp[r][c]

        right = self.calc(dungeon, dp, r, c + 1)
        down = self.calc(dungeon, dp, r + 1, c)

        min_hp = min(right, down) - dungeon[r][c]
        dp[r][c] = 1 if min_hp <= 0 else min_hp

        return dp[r][c]


sol = Solution()
print(sol.calculateMinimumHP([[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]))
