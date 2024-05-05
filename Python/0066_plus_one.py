from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] += 1
        index = len(digits) - 1
        while digits[index] == 10:
            digits[index] = 0

            if index > 0:
                digits[index - 1] += 1
            else:
                digits.insert(0, 1)
            index -= 1
        return digits


sol = Solution()
print(sol.plusOne([9,9,9]))
