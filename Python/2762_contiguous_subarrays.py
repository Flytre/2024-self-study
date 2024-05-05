from typing import List
import heapq


class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        right = 1
        mvh = [(nums[0], 0)]  # min-value heap
        xvh = [(-nums[0], 0)]  # max-value heap
        csa = 1  # continuous subarrays
        left = 0
        while right < len(nums):
            next_value = nums[right]
            heapq.heappush(mvh, (next_value, right))
            heapq.heappush(xvh, (-next_value, right))

            while abs(next_value - mvh[0][0] > 2):
                val, idx = heapq.heappop(mvh)
                left = max(left, idx+1)

            while abs(next_value - (-xvh[0][0])) > 2:
                val, idx = heapq.heappop(xvh)
                left = max(left, idx+1)

            right += 1
            csa += right - left

        return csa


sol = Solution()
print(sol.continuousSubarrays([1, 3, 0]))
