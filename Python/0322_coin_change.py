from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        recur = self.coinChangeRecur(coins, amount, {0: 0})
        return -1 if recur == 99999999 else recur

    def coinChangeRecur(self, coins: List[int], amount: int, dp: dict):
        if amount in dp.keys():
            return dp[amount]
        minimum_val = 99999999
        for coin in coins:
            if amount - coin >= 0:
                minimum_val = min(minimum_vneeal, 1 + self.coinChangeRecur(coins, amount - coin, dp))
        dp[amount] = minimum_val
        return minimum_val


sol = Solution()
print(sol.coinChange(coins=[1], amount=0))
