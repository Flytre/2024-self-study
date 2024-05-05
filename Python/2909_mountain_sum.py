from typing import List


class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        l_mins = [0] * len(nums)
        l_mins[0] = nums[0]
        for i in range(1, len(nums)):
            l_mins[i] = min(l_mins[i - 1], nums[i])

        r_mins = [0] * len(nums)
        r_mins[len(nums) - 1] = nums[-1]
        for i in reversed(range(0, len(nums) - 1)):
            r_mins[i] = min(r_mins[i + 1], nums[i])

        ret = min([
            (l_mins[i] + nums[i] + r_mins[i])
            if (l_mins[i] < nums[i] and r_mins[i] < nums[i]) else 1e10
            for i in range(0, len(nums))])
        return -1 if ret == 1e10 else ret

sol = Solution()
print(sol.minimumSum([6,5,4,3,4,5]))