from typing import *


class Solution:

    def swap(self, row, a, b):
        row[a], row[b] = row[b], row[a]

    def couple_of(self, val):
        return val + 1 if val % 2 == 0 else val - 1

    def ensure_couples_opp_side(self, row) -> int:
        swaps = 0
        swap_map = dict() # '0' for even index, '1' for odd index
        for val in row:
            if self.couple_of(val) in swap_map:

    def minSwapsCouples(self, row: List[int]) -> int:
        correct_pos = dict()
        for i in range(0, len(row), 2):
            correct_pos[row[i] + 1 if i % 2 == 0 else row[i] - 1] = i + 1
        print(correct_pos)


sol = Solution()
sol.minSwapsCouples(row=[0, 2, 1, 3])

# we need exactly 1 value from each couple to be in the left position
# anytime 2 from 1 couple
