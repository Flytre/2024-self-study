class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars = set()
        left, right, max_len = 0, 0, 0
        while right <= len(s) - 1:
            if s[right] not in chars:
                chars.add(s[right])
                right += 1
                max_len = max(max_len, right - left)
            else:
                while s[right] in chars:
                    chars.remove(s[left])
                    left += 1
        return max_len


sol = Solution()
print(sol.lengthOfLongestSubstring("pwwkew"))
