from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        def recur(tgt, index):
            if index >= len(candidates):
                return []
            if candidates[index] > tgt:
                return []

            tgt -= candidates[index]

            if tgt == 0:
                return [[candidates[index]]]

            return [[candidates[index]] + partial
                    for start in range(index, len(candidates))
                    for partial in recur(tgt, start)]

        return [solution
                for i in range(0, len(candidates))
                for solution in recur(target, i)]


sol = Solution()
print(sol.combinationSum([2, 3, 6, 7], 7))
