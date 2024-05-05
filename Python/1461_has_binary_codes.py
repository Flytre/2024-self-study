class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        return len(set(s[i:i + k] for i in range(0, len(s) - k + 1))) == 2 ** k


sol = Solution()
print(sol.hasAllCodes(s="01100", k=2))
