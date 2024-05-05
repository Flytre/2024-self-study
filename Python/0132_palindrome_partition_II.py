class Solution:
    MAX_INT = 999999

    def is_palindrome(self, s: str):
        return s == s[::-1]

    def minCut(self, s: str) -> int:
        dp = [self.MAX_INT] * len(s)
        dp[len(s) - 1] = 0
        for i in reversed(range(0, len(s) - 1)):
            for j in range(i + 1, len(s) + 1):
                if self.is_palindrome(s[i:j]):
                    dp[i] = min(dp[i], dp[j] + 1 if j < len(s) else 0)
        return dp[0]


sol = Solution()
print(sol.minCut("bb"))
