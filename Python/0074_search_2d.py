from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        while left <= right:
            mid = int((left + right) / 2)
            val = matrix[mid // n][mid % n]
            if val == target:
                return True
            elif val > target:
                right = mid - 1
            else:
                left = mid + 1
        return False


sol = Solution()
print(sol.searchMatrix([[1, 1]], 2))
