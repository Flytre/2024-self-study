class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        start, end, longest, freq = 0, 0, 0, dict()
        while end < len(s):
            freq[s[end]] = freq.get(s[end], 0) + 1
            interval_size = end - start + 1

            if all(interval_size - freq[val] > k for val in freq.keys()):
                freq[s[start]] -= 1
                start += 1
            else:
                longest = max(longest, interval_size)

            end += 1
        return longest


sol = Solution()
print(sol.characterReplacement("ABBB", 2))
