from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        set_word_dict = set(wordDict)
        dp = [False] * len(s)
        dp.append(True)
        for i in reversed(range(len(s))):
            for j in range(i + 1, len(s) + 1):
                if s[i:j] in set_word_dict:
                    dp[i] = dp[i] or dp[j]
        return dp[0]


sol = Solution()
print(sol.wordBreak(s="leetcode", wordDict=["leet", "code"]))
