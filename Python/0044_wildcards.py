from typing import List


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[None for _ in range(len(p))] for _ in range(len(s) + 1)]
        return Solution.match_recur(self, s, p, 0, 0, dp)

    def match_recur(self, s: str, p: str, s_index: int, p_index: int, dp: List[List[bool]]) -> bool:
        if s_index == len(s) and p_index == len(p):
            return True
        if p_index == len(p) or (s_index == len(s) and p[p_index] != "*"):
            return False
        if dp[s_index][p_index] is not None:
            return dp[s_index][p_index]
        if p[p_index] != '?' and p[p_index] != '*':
            dp[s_index][p_index] = (s[s_index] == p[p_index]) and Solution.match_recur(self, s, p, s_index + 1,
                                                                                       p_index + 1, dp)
            return dp[s_index][p_index]
        if p[p_index] == '?':
            dp[s_index][p_index] = Solution.match_recur(self, s, p, s_index + 1, p_index + 1, dp)
            return dp[s_index][p_index]

        non_wildcard = p_index
        while non_wildcard < len(p) and p[non_wildcard] == "*":
            non_wildcard += 1

        for i in range(s_index, len(s) + 1):
            if Solution.match_recur(self, s, p, i, non_wildcard, dp):
                dp[s_index][p_index] = True
                return True
        return False


sol = Solution()
print(sol.isMatch(s="aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", p="a**b*b*a*a*b*b"))
