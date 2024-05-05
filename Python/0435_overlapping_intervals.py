from typing import List


class Solution:
    def overlaps(self, a, b):
        return a[0] < b[1] and b[0] < a[1]

    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals)
        erasures, last = 0, intervals[0]

        for index in range(1, len(intervals)):
            if self.overlaps(last, intervals[index]):
                last = intervals[index] if intervals[index][1] < last[1] else last
                erasures += 1
            else:
                last = intervals[index]

        return erasures


sol = Solution()
print(sol.eraseOverlapIntervals([[0, 2], [1, 3], [2, 4], [3, 5], [4, 6]]))
