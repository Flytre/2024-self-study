class Solution:
    dp = {0: 0}
    max_val = 2 * 10 ** 9 + 1

    def minDays(self, n: int) -> int:
        if n in self.dp:
            return self.dp[n]
