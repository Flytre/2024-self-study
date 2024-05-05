class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        m, i = 1, 1
        while i < len(s):
            if s[i] == s[i - 1]:
                m += 1
            else:
                m = 1
            if m >= k:
                s = s[0:i - k + 1] + s[i + 1:]
                i -= k - 1
                m = 1
                while 0 < i < len(s) and s[i] == s[i - 1]:
                    i -= 1
            i += 1
        return s


sol = Solution()
print(sol.removeDuplicates("ybthyyyy", 4))
