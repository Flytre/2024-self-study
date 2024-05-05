class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        current_max_length = 1
        window_chars = set(s[0])
        start, end = 0, 0
        while end < len(s) - 1:
            end += 1
            while s[end] in window_chars:
                window_chars.remove(s[start])
                start += 1
            window_chars.add(s[end])
            current_max_length = max(current_max_length, end - start + 1)
        return current_max_length


sol = Solution()
print(sol.lengthOfLongestSubstring(""))
