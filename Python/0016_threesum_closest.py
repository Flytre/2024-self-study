from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        res = sum(nums[0:3])
        if res > target:
            return res
        for first in range(0, len(nums)):
            second, third = first + 1, len(nums) - 1
            while second < third:
                curr = nums[first] + nums[second] + nums[third]
                if curr < target:
                    second += 1
                elif curr > target:
                    third -= 1
                else:
                    return target
                res = curr if abs(curr - target) < abs(res - target) else res
        return res


sol = Solution()
print(sol.threeSumClosest(nums = [11,13,97,-136,53,47,-18,2,-33,536,-244,-270,313], target = 405))
