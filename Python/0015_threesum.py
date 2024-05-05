from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = list()
        nums = sorted(nums)
        v2i = {val: key for key, val in enumerate(nums)}
        for i1 in range(len(nums)):
            if i1 > 0 and nums[i1] == nums[i1 - 1]:
                continue
            for i2 in range(i1 + 1, len(nums)):
                if i2 > i1 + 1 and nums[i2] == nums[i2 - 1]:
                    continue
                if -(nums[i1] + nums[i2]) in v2i:
                    if v2i[-(nums[i1] + nums[i2])] > i2:
                        result.append([nums[i1], nums[i2], -nums[i1] - nums[i2]])
        return result


sol = Solution()
print(sol.threeSum([-1, 0, 1, 2, -1, -4]))
# [-8,-1, 2,3,5,8], then point at [-8,8]
