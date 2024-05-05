from typing import List

#TODO: DP
class Solution:
    def is_palindrome(self, s: str):
        return s == s[::-1]

    def partition(self, s: str) -> List[List[str]]:
        if len(s) == 0:
            return None

        ret = []
        for i in range(0, len(s)):
            substr = s[0:i + 1]
            if self.is_palindrome(substr):
                recur = self.partition(s[i + 1:])
                if recur is None:
                    ret += [[substr]]
                else:
                    for result in recur:
                        ret += [[substr] + result]
        return ret


sol = Solution()
print(sol.partition("ababa"))
