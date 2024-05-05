from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s) < len(t):
            return ""
        start, end = 0, 0
        t_freq, s_freq = Counter(t), Counter("")
        min_substr, min_length = "", 999999

        while end < len(s):
            s_freq[s[end]] = s_freq.get(s[end], 0) + 1
            if self.all_values_greater(t_freq, s_freq):
                while s_freq[s[start]] > t_freq[s[start]]:
                    s_freq[s[start]] -= 1
                    start += 1
                if end - start + 1 < min_length:
                    min_length = end - start + 1
                    min_substr = s[start:end + 1]
            end += 1

        return min_substr

    def all_values_greater(self, base: dict, attempt: dict):
        return all(val in attempt.keys() and attempt[val] >= base[val] for val in base.keys())


sol = Solution()
print(sol.minWindow("ADOBECODEBANC", "ABC"))
