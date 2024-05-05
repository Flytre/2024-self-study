from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        variant_set = set(nums)
        dp = dict()
        longest = 0
        for num in nums:
            longest = max(longest, self.calc_len(num, variant_set, dp))
        return longest

    def calc_len(self, num, variant_set: set, dp: dict) -> int:
        if num in dp:
            return dp[num]
        if num not in variant_set:
            return 0
        dp[num] = 1 + self.calc_len(num + 1, variant_set, dp)
        return dp[num]


sol = Solution()
print(sol.longestConsecutive([100, 4, 200, 1, 3, 2]))
