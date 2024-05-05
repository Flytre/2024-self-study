from typing import List


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = [dict() for x in range(len(nums) + 1)]
        dp[len(nums)][0] = 1
        for i in reversed(range(0, len(nums))):
            for key in dp[i+1].keys():
                dp[i][key + nums[i]] = dp[i].get(key + nums[i], 0) + dp[i+1][key]
                dp[i][key - nums[i]] = dp[i].get(key - nums[i], 0) + dp[i+1][key]
        return dp[0].get(target, 0)


sol = Solution()
print(sol.findTargetSumWays(nums=[1, 1, 1, 1, 1], target=3))
