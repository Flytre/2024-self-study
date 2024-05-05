import string
from typing import List


class Solution:
    def strongPasswordChecker(self, password: str) -> int:
        short_steps = (6 - len(password)) if len(password) < 6 else 0
        long_steps = (len(password) - 20) if len(password) > 20 else 0
        char_steps = self.parse_flags(password)

        steps = 0
        char = password[0]
        ct = 1
        pass_len = len(password)
        mod_char_steps = char_steps
        deletes_reserved = self.reserve_deletes(password)
        free_deletes = max(len(password) - 20, 0) - deletes_reserved[0] - deletes_reserved[1]
        for i in range(1, len(password) + 1):
            if i < len(password) and password[i] == char:
                ct += 1
            else:
                if ct % 3 == 0 and deletes_reserved[0] > 0:
                    ct -= 1
                    deletes_reserved[0] -= 1
                    steps += 1
                if ct > 3 and ct % 3 == 1 and deletes_reserved[1] >= 2:
                    ct -= 2
                    deletes_reserved[1] -= 2
                    steps += 2
                while ct >= 3:
                    if pass_len < 6:  # insert
                        ct -= 2
                        pass_len += 1
                        mod_char_steps -= 1
                    elif free_deletes > 0:  # delete
                        ct -= 1
                        pass_len -= 1
                        free_deletes -= 1
                    else:  # replace
                        ct -= 3
                        mod_char_steps -= 1
                    steps += 1
                if i < len(password):
                    char = password[i]
                    ct = 1
        mod_char_steps = max(mod_char_steps, 0)
        return max([steps + mod_char_steps, short_steps, long_steps + char_steps])

    def parse_flags(self, password: str) -> int:
        has_upper = False
        has_lower = False
        has_digit = False
        for i in range(0, len(password)):
            if password[i] in string.ascii_uppercase:
                has_upper = True
            elif password[i] in string.ascii_lowercase:
                has_lower = True
            elif password[i] in string.digits:
                has_digit = True
        flags = 3
        if has_upper:
            flags -= 1
        if has_lower:
            flags -= 1
        if has_digit:
            flags -= 1
        return flags

    def reserve_deletes(self, password: str) -> List[int]:
        char = password[0]
        ct = 1
        mod_cts = [0, 0, 0]
        deletes_reserved = [0, 0]
        deletes = max(len(password) - 20, 0)
        for i in range(1, len(password) + 1):
            if i < len(password) and password[i] == char:
                ct += 1
            else:
                if ct >= 3:
                    mod_cts[ct % 3] += 1
                if i < len(password):
                    char = password[i]
                ct = 1
        deletes_reserved[0] += min(deletes, mod_cts[0])
        deletes -= deletes_reserved[0]
        deletes_reserved[1] += (min(deletes, 2 * mod_cts[1]) // 2) * 2
        deletes -= deletes_reserved[1]
        return deletes_reserved


solution = Solution()
assert solution.strongPasswordChecker("1337C0d3") == 0
assert solution.strongPasswordChecker("a") == 5
assert solution.strongPasswordChecker("aA1") == 3
assert solution.strongPasswordChecker("!!!") == 3
assert solution.strongPasswordChecker("aaaaaaaaaaaaaaaaaaaa") == 6
assert solution.strongPasswordChecker("aaaaa") == 2
assert solution.strongPasswordChecker("aaa111") == 2
assert solution.strongPasswordChecker("ABABABABABABABABABAB1") == 2
assert solution.strongPasswordChecker("!.!.!.!.!.!.!.!.!.!.!.!.!") == 8
assert solution.strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc") == 8
assert solution.strongPasswordChecker("aaaaaCCCC!.!.!.!.!.!.!0") == 4
assert solution.strongPasswordChecker("aaaaaBBBBB0000000!.!.!") == 5
assert solution.strongPasswordChecker("aaaaAAAAAA000000123456") == 5
assert solution.strongPasswordChecker("A1234567890aaabbbbccccc") == 4
assert solution.strongPasswordChecker("1234567890123456Baaaaa") == 3