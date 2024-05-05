from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest, profit = prices[0], 0

        for price in prices:
            lowest = min(lowest, price)
            profit = max(profit, price - lowest)
        return profit



sol = Solution()
print(sol.maxProfit([7, 1, 5, 3, 6, 4]))
