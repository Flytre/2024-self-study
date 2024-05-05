from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        cc = [i for i in range(0, len(grid) * len(grid[0]))]
        for r in range(0, len(grid)):
            for c in range(0, len(grid[0])):
                if self.get_val(grid, r, c) == "0":
                    cc[r * len(grid[0]) + c] = -1
                    continue
                offsets = [lambda r0, c0: (r0 - 1, c0), lambda r0, c0: (r0 + 1, c0), lambda r0, c0: (r0, c0 - 1),
                           lambda r0, c0: (r0, c0 + 1)]
                for offset in offsets:
                    rp, cp = offset(r, c)
                    if self.get_val(grid, rp, cp) == "1" and self.component(cc, r * len(grid[0]) + c) != self.component(
                            cc, rp * len(grid[0]) + cp):
                        self.union(cc, self.component(cc, r * len(grid[0]) + c), self.component(cc, rp * len(grid[0]) + cp))
        for i in range(0, len(cc)):
            self.component(cc, i)
        return len(set(cc).difference({-1}))

    def get_val(self, grid: List[List[str]], r: int, c: int) -> str:
        if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]):
            return "0"
        return grid[r][c]

    def component(self, cc: list, index: int) -> int:
        if cc[index] == index or cc[index] == -1:
            return index
        cc[index] = self.component(cc, cc[index])
        return cc[index]

    def union(self, cc: list, a: int, b: int):
        cc[self.component(cc, b)] = self.component(cc, a)


sol = Solution()
print(sol.numIslands(
    [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"], ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]))
