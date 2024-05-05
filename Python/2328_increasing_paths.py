from typing import List, Dict, Tuple, Optional


class Solution:
    NEXT_LOC = [lambda k: (k[0] - 1, k[1]),
                lambda k: (k[0] + 1, k[1]),
                lambda k: (k[0], k[1] + 1),
                lambda k: (k[0], k[1] - 1)]
    MOD = (10 ** 9 + 7)

    def countPaths(self, grid: List[List[int]]) -> int:
        return self.helper(grid, None, 1)

    def helper(self, grid: List[List[int]], old_mirror: Optional[Dict[Tuple[int, int], int]], n: int) -> int:
        if n == 1:
            mirror = {(x, y): 1 for x in range(len(grid)) for y in range(len(grid[0]))}
            return (len(grid[0]) * len(grid) + self.helper(grid, mirror, n + 1)) % self.MOD

        if len(old_mirror.keys()) == 0:
            return 0

        new_mirror = dict()
        for loc in old_mirror.keys():
            for traverse_type in self.NEXT_LOC:
                mutated_loc = traverse_type(loc)
                if mutated_loc[0] < 0 or mutated_loc[0] >= len(grid) or mutated_loc[1] < 0 or mutated_loc[1] >= len(grid[0]):
                    continue
                if grid[mutated_loc[0]][mutated_loc[1]] < grid[loc[0]][loc[1]]:
                    new_mirror[mutated_loc] = new_mirror.get(mutated_loc, 0) + old_mirror[loc]
        summ = sum(new_mirror.values())
        return (summ + self.helper(grid, new_mirror, n + 1)) % self.MOD

sol = Solution()
print(sol.countPaths(grid = [[1,1],[3,4],[1,1]]))