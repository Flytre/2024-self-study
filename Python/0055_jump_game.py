from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        last_jump = len(nums) - 1
        for val in reversed(range(0, len(nums))):
            if val + nums[val] >= last_jump:
                last_jump = val
        return last_jump == 0


sol = Solution()
print(sol.canJump([3, 2, 1, 0, 4]))
