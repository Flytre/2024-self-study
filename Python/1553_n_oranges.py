class Solution:
    dp = {0: 0}
    max_val = 2 * (10 ** 9) + 1

    def minDays(self, n: int) -> int:
        return self.minDaysHelper(n, 0)

    def minDaysHelper(self, n: int, depth: int) -> int:
        if n in self.dp:
            return self.dp[n]

        self.dp[n] = self.max_val

        if depth >= 50:
            return self.max_val

        if n % 3 == 0:
            self.dp[n] = 1 + self.minDaysHelper(n - 2 * n / 3, depth + 1)
        if n % 2 == 0:
            self.dp[n] = min(self.dp[n], 1 + self.minDaysHelper(n / 2, depth + 1))

        self.dp[n] = min(self.dp[n], 1 + self.minDaysHelper(n - 1, depth + 1))

        return self.dp[n]


sol = Solution()
print(sol.minDays(1421))
x = 1