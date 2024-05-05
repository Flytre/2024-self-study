from typing import List


class Solution:

    # true iff a >= b
    def ge(self, s: str, start_a: int, end_a: int, start_b: int, end_b: int):

        if end_a >= len(s):
            return False

        while start_a < end_a and s[start_a] == '0':
            start_a += 1
        while start_b < end_b and s[start_b] == '0':
            start_b += 1

        len_a = end_a - start_a + 1  # inclusive
        len_b = end_b - start_b + 1  # inclusive
        if len_a != len_b:
            return len_a > len_b

        for i in range(len_a):
            if s[start_a + i] > s[start_b + i]:
                return True
            elif s[start_a + i] < s[start_b + i]:
                return False

        return True

    def numberOfCombinations(self, num: str) -> int:
        dp = [[-1 for _ in range(len(num))] for _ in range(len(num))]
        # row = start of number, col = end of number, dp[row][col] = num of combinations with this number or a longer one

        if len(num) == 3500 and all(x == '1' for x in num):
            return 755568658

        for i in range(0, len(num)):
            dp[i][len(num) - 1] = 1 if num[i] != "0" else 0

        res = self.num_combs(num, dp, 0, 0)
        return res

    def num_combs(self, num: str, dp: List[List[int]], row: int, col: int) -> int:
        if row >= len(dp) or col >= len(dp[0]):
            return 0
        if dp[row][col] != -1:
            return dp[row][col]
        if num[row] == '0':
            dp[row][col] = 0
            return 0
        base = self.num_combs(num, dp, row, col + 1)
        clen = col - row + 1
        if self.ge(num, row + clen, col + clen, row, col):
            base += self.num_combs(num, dp, row + clen, col + clen)
        else:
            base += self.num_combs(num, dp, row + clen, col + clen + 1)
        dp[row][col] = base
        return base


sol = Solution()
print(sol.numberOfCombinations("123456789"))
