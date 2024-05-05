from typing import List, Set


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]
        recur = self.subsets(nums[:-1])
        for i in range(0, len(recur)):
            recur.append(recur[i] + [nums[-1]])
        return recur


sol = Solution()
print(sol.subsets([1, 2, 3]))
